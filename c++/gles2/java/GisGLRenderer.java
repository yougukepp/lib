package zydz.gis.gles2;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import android.opengl.Matrix;
import android.util.Log;

public class GisGLRenderer implements GLSurfaceView.Renderer {

    private static final String TAG = "MyGLRenderer";
    
    private GisLines   mLines;
    private GisPolygon   mPolygon;
    private GisArc mArc;
    private final float[] mProjMatrix = new float[16];

    public volatile float mAngle;

    @Override
    public void onSurfaceCreated(GL10 unused, EGLConfig config) {
        GLES20.glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        mLines   = new GisLines();
        mPolygon = new GisPolygon();
        mArc = new GisArc();
    }

    @Override
    public void onDrawFrame(GL10 unused) {
        GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT);        
        
        float[][] points1 = {
        	{-0.9f, -0.9f},
        	{0.9f, 0.9f}        	
        };
        float[] rgb1 = {1.0f, 0.0f, 0.0f};        
        mLines.draw(points1, rgb1);
        float[][] point2 = {
            	{-0.9f, 0.9f},
            	{0.9f, -0.9f}        	
            };
        float[] rgb2 = {0.0f, 1.0f, 0.0f};
        mLines.draw(point2, rgb2);
        
        float[][] points3 = {
            	{0.0f, 0.9f},
            	{-0.9f, 0f},
            	{0.0f, -0.9f},
            	{0.9f, 0f} 
            };
        float[] rgb3 = {0.0f, 0.0f, 1.0f};
        mPolygon.draw(points3, rgb3);
        
        float[][] points4 = {
            	{-0.9f, 0.9f},
            	{-0.9f, 0f},
            	{0.0f, -0.9f},
            	{0.9f, 0f} 
            };
        float[] rgb4 = {0.0f, 0.0f, 1.0f};
        mArc.draw(points4, rgb4);
        /*
        float[] rect = { -0.9f, 0.9f, 1.8f, 1.8f};
        float[] rgb4 = {0.0f, 0.0f, 1.0f};
        mArc.draw(rect, 0, 90, rgb4);*/
    }

    @Override
    public void onSurfaceChanged(GL10 unused, int width, int height) {
        GLES20.glViewport(0, 0, width, height);
        float ratio = (float) width / height;
        Matrix.frustumM(mProjMatrix, 0, -ratio, ratio, -1, 1, 3, 7);
    }

    public static int loadShader(int type, String shaderCode){
        int shader = GLES20.glCreateShader(type);
        GLES20.glShaderSource(shader, shaderCode);
        GLES20.glCompileShader(shader);
        return shader;
    }

    public static void checkGlError(String glOperation) {
        int error;
        while ((error = GLES20.glGetError()) != GLES20.GL_NO_ERROR) {
            Log.e(TAG, glOperation + ": glError " + error);
            throw new RuntimeException(glOperation + ": glError " + error);
        }
    }
}


package zydz.gis.gles2;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;

import android.opengl.GLES20;

class GisLines{
	final String TAG = "GisLines.";
	
    private String vertexShaderCode =
        "attribute vec4 vPosition;" +
        "void main() {" +
        "  gl_Position = vPosition;" +
        "}";

    private String fragmentShaderCode =
        "precision mediump float;" +
        "uniform vec4 vColor;" +
        "void main() {" +
        "  gl_FragColor = vColor;" +
        "}";

    protected int mProgram;
    protected int mPosHandle;
    protected int mColorHandle;
    
    public GisLines() {
        mProgram = GLES20.glCreateProgram();        
        Link();  
    }

    protected void Link() {
        int vertexShader = GisGLRenderer.loadShader(GLES20.GL_VERTEX_SHADER,
                getVertexShaderCode());
        int fragmentShader = GisGLRenderer.loadShader(GLES20.GL_FRAGMENT_SHADER,
                getFragmentShaderCode());
        GLES20.glAttachShader(mProgram, vertexShader);
        GLES20.glAttachShader(mProgram, fragmentShader);
        GLES20.glLinkProgram(mProgram);
	}

	public void draw(float[][] points, float[] rgb)
    {
    	draw(points, rgb, GLES20.GL_LINE_STRIP);
    }
    
    protected void draw(float[][] points, float[] rgb, int drawType)    
    {
        int COORDS_PER_VERTEX = 2;        
        FloatBuffer vertexBuffer = null;
        
        ByteBuffer bb = ByteBuffer.allocateDirect(points.length * points[0].length * 4);
        bb.order(ByteOrder.nativeOrder());
        vertexBuffer = bb.asFloatBuffer();
        int iMax = 0; 
        
        iMax = points.length;      
        for(int i = 0; i<iMax; i++)
        {
            int jMax = points[i].length;
            for(int j=0; j<jMax; j++)
            {
                vertexBuffer.put(points[i][j]);
            }
        }
        vertexBuffer.position(0);
        
        float color[] = {rgb[0], rgb[1], rgb[2], 1.0f};
     
        GLES20.glUseProgram(mProgram);
        mColorHandle = GLES20.glGetUniformLocation(mProgram, "vColor");
        GLES20.glUniform4fv(mColorHandle, 1, color, 0);
        
        mPosHandle = GLES20.glGetAttribLocation(mProgram, "vPosition");
        GLES20.glEnableVertexAttribArray(mPosHandle);        
        GLES20.glVertexAttribPointer(mPosHandle, COORDS_PER_VERTEX,
                GLES20.GL_FLOAT, false,
                0, vertexBuffer);

        GLES20.glDrawArrays(drawType, 0, iMax);
        GLES20.glDisableVertexAttribArray(mPosHandle);
    }

	protected String getVertexShaderCode() {
		return vertexShaderCode;
	}

	protected void setVertexShaderCode(String vertexShaderCode) {
		this.vertexShaderCode = vertexShaderCode;
	}

	protected String getFragmentShaderCode() {
		return fragmentShaderCode;
	}

	protected void setFragmentShaderCode(String fragmentShaderCode) {
		this.fragmentShaderCode = fragmentShaderCode;
	}
}


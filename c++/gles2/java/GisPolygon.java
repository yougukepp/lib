package zydz.gis.gles2;

import android.opengl.GLES20;

class GisPolygon  extends GisLines{  
	final String TAG = "GisPolygon.";
	
    public GisPolygon() {
    	super();
    }

    @Override
    public void draw(float[][] points, float[] rgb){        
    	super.draw(points, rgb, GLES20.GL_LINE_LOOP);
    }
}

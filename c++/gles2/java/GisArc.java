package zydz.gis.gles2;

import android.opengl.GLES20;

class GisArc extends  GisLines{  
	final String TAG = "GisPolygon.";
	
    private String vertexShaderCode =
    		"attribute vec4 vPosition;" +
            "void main() {" +
            "  gl_Position = vPosition;" +
            "}";
    
    private String fragmentShaderCode =
            "precision mediump float;" +
            "uniform vec4 vColor;" +
            "void main() {" +
            "  gl_FragColor = {1.0, 1.0, 1.0, 1.0};" +
            "}";
    
    public GisArc() {
    	super();
    	super.setFragmentShaderCode(fragmentShaderCode);
    	super.setVertexShaderCode(vertexShaderCode);
    	super.Link();
    }

    public void draw(float[] rect, float startAngle, float endAngle, float[] rgb){
    	;
    }
    
    //protected void draw(float[][] points, float[] rgb){
    public void draw(float[][] points, float[] rgb){
    	super.draw(points, rgb, GLES20.GL_LINE_STRIP);
    }    
}
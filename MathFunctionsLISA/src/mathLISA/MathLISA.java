package mathLISA;

import oml.basis.*;

public abstract class MathLISA extends Verfahren implements IMathLISA, VerfahrenParaItf  {
	
	public static final String UID = "F6BB87BE-691E-4381-88CA-2CA3D5AD672F";
	
	public String getUID() {
        return UID;
    }

    public String getNameVerfahren() {
        return "Math";
    }

    public String getVersionVerfahren() {
        return "1.0.0";
    }
    
    public MathLISA(Lsa lsa) {
    	super(lsa);
    	
    	initPara();
    	initRefs();
    }
    
    public void initPara() {
    	
    }

    public void initRefs() {
    	
    }
    
    public void initLogik(Logik logik) {
    	
    }
    
	public abstract float wurzel(float x);
	public abstract float wurzelExp(float x, float n);
	public abstract float quadrat(float x);
	public abstract int quadrat(int x);
	public abstract float exp(float x);
	public abstract float pot(float x, float y);
	public abstract int pot(int x, int y);
	public abstract float ln(float x);
	public abstract int modulo(int x, int y);
	public abstract float modulo(float x, float y); // added a modulo function and changed the return type of the upper function
	public abstract float sum(float[] values);
	public abstract float durchschnitt(float[] values);
	public abstract float varianz(float[] values);
	public abstract float standardabw(float[] values);
	public abstract float median(float[] values);
	public abstract float min(float[] values);
	public abstract int min(int[] values);
	public abstract float min(float x, float y);
	public abstract float min(int x, int y);
	public abstract float max(float[] values);
	public abstract int max(int[] values);
	public abstract float max(float x, float y);
	public abstract float max(int x, int y);
	public abstract int round(float x);
	public abstract float round(float x, int position);
	public abstract float Zufallszahl(float start, float size);
	public abstract int Zufallszahl(int start, int size);
	public abstract int Absolut(int x);
	public abstract float Absolut(float x);
    
}

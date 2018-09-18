package MathLISA;

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
    
}

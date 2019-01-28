package mathLISA;

import java.util.Arrays;

import oml.basis.*;

public class MathLISAImpl extends MathLISA implements IMathLISA {
	
	public MathLISAImpl(Lsa lsa) {
		super(lsa);
	}

	@Override
	public void runMain(int arg0) {
		
	}

	@Override
	public void runPost() {
		
	}
	
    public float getPI() {
    	return PI;
    }
    public float getE() {
    	return E;
    }
	
	public float wurzel(float x) {
		float result = (float) Math.sqrt(x);

		if (Float.isNaN(result) || Float.isInfinite(result)) throw new IllegalArgumentException("The given Argument is not correct! argument: " + x);
		
		return result;
	}
	
	public float wurzelExp(float x, float n) {
		float result = (n!=0) ? (float) Math.pow(x, (double)(1/n)) : Float.NaN;
		
		if (Float.isNaN(result) || Float.isInfinite(result)) throw new IllegalArgumentException("The given Argument is not correct! argument: " + x);
		
		return result;
	}
	
	public float quadrat(float x) {
		return (float) Math.pow(x, 2);
	}
	
	public int quadrat(int x) {
		return (int)quadrat((float)x);
	}
	
	public float exp(float x) {
		return (float) Math.pow(E, x);
	}
	
	public float pot(float x, float y) {
		float result = (float) Math.pow(x, y);
		
		return result;
	}
	
	public int pot(int x, int y) {
		return (int)pot((float)x, (float)y);
	}
	
	public float ln(float x) {
		float result = (float) Math.log(x);
		
		if (Float.isNaN(result) || Float.isInfinite(result)) throw new IllegalArgumentException("The given Argument is not correct! argument: " + x);
		
		return result;
	}
	
	public int modulo(int x, int y) {
		return (int)modulo((float)x, (float)y);
	}
	
	public float modulo(float x, float y) { 
		if (y == 0) throw new IllegalArgumentException("The modul y can not be 0!");
		if (Float.isInfinite(y) || Float.isNaN(y)) throw new IllegalArgumentException("The given parameter is not correct! x: " + x + "; y: " + y);
		
		float result = (float) (x - ((int)(x/y)*y));
		
		return result;
	}
	
	public float sum(Lisa_Float[] values) {
		if (values.length <= 0) throw new IllegalArgumentException();
		
		float sum = 0;
		
		for (Lisa_Float v : values) {
			sum+=v.value;
		}
		
		return sum;
	}
	
	public float durchschnitt(Lisa_Float[] values) {
		if (values.length <= 0) throw new IllegalArgumentException();
		
		float sum = sum(values);
		
		return sum/values.length;
	}
	
	public float varianz(Lisa_Float[] values) {
		if (values.length <= 0) throw new IllegalArgumentException();
		
		float average = durchschnitt(values);
		
		float varianz = 0;
		for (Lisa_Float v : values) {
			varianz += quadrat(v.value - average);
		}
		
		return varianz/values.length;
	}
	
	public float standardabw(Lisa_Float[] values) {
		if (values.length <= 0) throw new IllegalArgumentException();
		
		float varianz = varianz(values);
		
		return wurzel(varianz);
	}
	
	private float[] convertLisa_FloatArrayToFloatArray(Lisa_Float[] array) {
		float[] result = new float[array.length];
		
		for (int i = 0; i < result.length; i++) result[i] = array[i].value;
		
		return result;
	}
	
	public float median(Lisa_Float[] values) {
		if (values.length <= 0) throw new IllegalArgumentException();
		
		float[] data = convertLisa_FloatArrayToFloatArray(values);
		
		// sort array
		Arrays.sort(data);
		
		float median = 0;
		if (Math.floorMod(data.length, 2) == 0)
			median = ((float)data[data.length/2] + (float)data[(data.length/2) - 1])/2;
		else
			median = (float) data[data.length/2];
		
		return median;
	}
	
	public float min(Lisa_Float[] values) {
		float min = Float.POSITIVE_INFINITY;
		for (Lisa_Float v : values) min = Math.min(v.value, min);
		
		return min;
	}
	
	public int min(Lisa_Int[] values) {
		int min = Integer.MAX_VALUE;
		for (Lisa_Int v : values) min = Math.min(v.value, min);
		
		return min;
	}
	
	public float minAtomar(float x, float y) {
		return Math.min(x, y);
	}
	
	public float minAtomar(int x, int y) {
		return Math.min(x, y);
	}
	
	public float max(Lisa_Float[] values) {
		float max = Float.NEGATIVE_INFINITY;
		for (Lisa_Float v : values) max = Math.max(v.value, max);
		
		return max;
	}
	
	public int max(Lisa_Int[] values) {
		int max = Integer.MIN_VALUE;
		for (Lisa_Int v : values) max = Math.max(v.value, max);
		
		return max;
	}
	
	public float maxAtomar(float x, float y) {
		return Math.max(x, y);
	}
	
	public float maxAtomar(int x, int y) {
		return Math.max(x, y);
	}
	
	public int round(float x) {
		return Math.round(x);
	}
	
	public float roundPosition(float x, int position) {
		if (position < 0) throw new IllegalArgumentException("Die Position darf nicht negativ sein!");
		
		float pow = (float) Math.pow(10, position);
		float round = Math.round(x*pow)/pow;
		
		return round;
	}
	
	public float Zufallszahl(float start, float size) {
		if (size <= 0) throw new IllegalArgumentException("Die Reichweite der Zufallszahl darf nicht negativ sein!");
		
		float sum = start + size;
		if (sum > Float.MAX_VALUE) size = Float.MAX_VALUE - start;
		
		float random = (float) (Math.random()*size);
		
		return random+start;
	}
	
	public int Zufallszahl(int start, int size) {
		return Math.round(Zufallszahl((float)start, (float)size));
	}

	@Override
	public int Absolut(int x) {
		return Math.abs(x);
	}

	@Override
	public float Absolut(float x) {
		return Math.abs(x);
	}
}

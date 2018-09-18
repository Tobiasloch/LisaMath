package MathLISA;
import java.lang.Math;
import java.util.Arrays;

public interface IMathLISA {

	public static final double E = Math.E;
	public static final double PI = Math.PI;
	
	public static double getE() {
		return E;
	}
	
	public static double getPI() {
		return PI;
	}
	
	/**
	 * 
	 * Es wird die sqrt Funktion der Mathe Bibliothek von Java verwendet um x zu berechnen.
	 * 
	 * @param Radikand x
	 * @return Quadratwurzel von x
	 * @author t.loch
	 * 
	 * */
	public static double wurzel(double x) { // Wurzel x
		return Math.sqrt(x);
	}

	/**
	 * 
	 * Es wird die pow Funktion der Mathe Bibliothek verwendet, welche die n-te Wurzel berechnet.
	 * Dabei ist n der Nenner des Bruches im Exponenten der Potenz.
	 * 
	 * @param x ist der Radikand und n ist die Wurzelpotenz
	 * @return n-te Wurzel von x
	 * @author t.loch
	 * 
	 * */
	public static double wurzelExp(double x, double n) { // n-Wurzel von x
		return Math.pow(x, (1/n));
	}
	
	/**
	 * 
	 * Nutzt die pow Funktion der Mathe Bibliothek von Java um x zu quadrieren.
	 * 
	 * @param Basis x
	 * @return Quadrat von x
	 * @author t.loch
	 * 
	 * */
	public static double quadrat(double x) {
		return Math.pow(x, 2);
	}
	
	/**
	 * 
	 * Nutzt die pow Funktion der Mathe Bibliothek von Java um x zu quadrieren.
	 * 
	 * @param Basis x
	 * @return Quadrat von x
	 * @author t.loch
	 * 
	 * */
	public static long quadrat(long x) {
		return (long)quadrat((double)x);
	}
	
	
	/**
	 * 
	 * Nutzt die pow Funktion der Mathe Bibliothek von Java um eine Potenz mit einem beliebigen Exponenten zu berechnen.
	 * Sie entspricht der natuerlichen Exponentialfunktion.
	 * 
	 * @param Basis e und Exponent x (e^x)
	 * @return Potenz von e^x
	 * @author t.loch
	 * 
	 * */
	public static double exp(double x) {
		return Math.pow(E, x);
	}
	
	/**
	 * 
	 * Nutzt die pow Funktion der Mathe Bibliothek von Java um eine Potenz mit einem beliebigen Exponenten zu berechnen.
	 * 
	 * @param Basis x und Exponent y (x^y)
	 * @return Potenz von x^y
	 * @author t.loch
	 * 
	 * */
	public static double pot(double x, double y) {
		return Math.pow(x, y);
	}
	
	/**
	 * 
	 * Nutzt die pow Funktion der Mathe Bibliothek von Java um eine Potenz mit einem beliebigen Exponenten zu berechnen.
	 * 
	 * @param Basis x und Exponent y (x^y)
	 * @return Potenz von x^y
	 * @author t.loch
	 * 
	 * */
	public static long pot(long x, long y) {
		return (long)pot((double)x, (double)y);
	}
	
	/**
	 * 
	 * Nutzt die log Funktion der Mathe Bibliothek von Java um den natuerlichen Logarithmus (ln) zu berechnen.
	 * 
	 * @param Wurzel x zur Basis e
	 * @return Der Exponent von e
	 * @author t.loch
	 * 
	 * */
	public static double ln(double x) {
		return Math.log(x);
	}
	
	/**
	 * 
	 * Berechnet den Rest von x und y.
	 * 
	 * @param Zahl x und Modul y
	 * @return Rest von x/y
	 * @author t.loch
	 * 
	 * */
	public static double modulo(long x, long y) {
		return Math.floorMod(x,  y);
	}
	
	
	/**
	 * 
	 * Berechnet die Summe des angegebenen buffers.
	 * 
	 * @param Array von double Werten
	 * @return Summe von values
	 * @author t.loch
	 * 
	 * 
	 * */
	public static double sum(double[] values) {
		if (values.length <= 0) throw new IllegalArgumentException();
		
		double sum = 0;
		
		for (double v : values) {
			sum+=v;
		}
		
		return sum;
	}
	
	/**
	 * 
	 * Berechnet das arithmetische Mittel des Buffers values.
	 * 
	 * @param Array von double values
	 * @return gibt das arithmetische Mittel von values aus
	 * @author t.loch
	 * 
	 * */
	public static double durchschnitt(double[] values) {
		if (values.length <= 0) throw new IllegalArgumentException();
		
		double sum = sum(values);
		
		return sum/values.length;
	}
	
	/**
	 * 
	 * Berechnet die Varianz des buffers values.
	 * 
	 * @param Array von double values
	 * @return gibt die Varianz von values zurueck
	 * @author t.loch
	 * 
	 * */
	public static double varianz(double[] values) {
		if (values.length <= 0) throw new IllegalArgumentException();
		
		double average = durchschnitt(values);
		
		double varianz = 0;
		for (double v : values) {
			varianz += quadrat(v - average);
		}
		
		return varianz/values.length;
	}
	
	/**
	 * 
	 * Berechnet die Standardabweichung des buffers values
	 * 
	 * @param Array von double Werten
	 * @return gibt die standardabweichung der eingabewerte zurueck
	 * @author t.loch
	 * 
	 * */
	public static double standardabw(double[] values) {
		if (values.length <= 0) throw new IllegalArgumentException();
		
		double varianz = varianz(values);
		
		return wurzel(varianz);
	}
	
	/**
	 * 
	 * Berechnet den Median des double arrays
	 * 
	 * @param double array der Eingabewerte
	 * @return median der Eingabewerte
	 * @author t.loch
	 * 
	 * */
	public static double median(double[] values) {
		if (values.length <= 0) throw new IllegalArgumentException();
		
		Arrays.sort(values);
		
		double median = 0;
		if (Math.floorMod(values.length, 2) == 0)
			median = ((double)values[values.length/2] + (double)values[(values.length/2) - 1])/2;
		else
			median = (double) values[values.length/2];
		
		return median;
	}
	
	/**
	 * 
	 * gibt den minimalen wert des Buffers zuraeck
	 * 
	 * @author t.loch
	 * 
	 * */
	public static double min(double[] values) {
		double min = Double.POSITIVE_INFINITY;
		for (double v : values) min = Math.min(v, min);
		
		return min;
	}
	
	public static long min(long[] values) {
		long min = Long.MAX_VALUE;
		for (long v : values) min = Math.min(v, min);
		
		return min;
	}
	
	/**
	 * 
	 * gibt den minimalen Wert von x und y zurueck durch benutzen von Math.min
	 * 
	 * @author t.loch
	 * 
	 * */
	public static double min(double x, double y) {
		return Math.min(x, y);
	}
	
	public static double min(long x, long y) {
		return Math.min(x, y);
	}
	
	/**
	 * 
	 * gibt den maximalen Wert des double arrays zurueck
	 * 
	 * @author t.loch
	 * 
	 * */
	public static double max(double[] values) {
		double max = Double.NEGATIVE_INFINITY;
		for (double v : values) max = Math.max(v, max);
		
		return max;
	}
	
	public static long max(long[] values) {
		long max = Long.MIN_VALUE;
		for (long v : values) max = Math.max(v, max);
		
		return max;
	}
	
	/**
	 * 
	 * gibt den maximalen Wert von x und y zurueck durch benutzen von Math.max
	 * 
	 * @author t.loch
	 * 
	 * */
	public static double max(double x, double y) {
		return Math.max(x, y);
	}
	
	public static double max(long x, long y) {
		return Math.max(x, y);
	}
	
	/**
	 * 
	 * Rundet den gegebenen Wert. Bei .5 wird aufgerundet, bei kleiner .5 wird abgerundet
	 * 
	 * @author t.loch
	 * 
	 * */
	public static long round(double x) {
		return Math.round(x);
	}
	
	
	/**
	 * 
	 * Rundet den gegebenen Wert auf eine gegebene Nachkommastelle. Bei .5 wird aufgerundet, bei kleiner .5 wird abgerundet
	 * 
	 * @param x ist der zu rundende Wert und position ist die Nackommastelle
	 * @return der gerundete Wert
	 * @author t.loch
	 * 
	 * */
	public static double round(double x, int position) {
		if (position < 0) throw new IllegalArgumentException();
		
		double pow = Math.pow(10, position);
		double round = Math.round(x*pow)/pow;
		
		return round;
	}
	
	/**
	 * 
	 * generiert eine Zufallszahl
	 * 
	 * @param start ist der beginn des Intervalls und size die Groeﬂe
	 * @return eine zufallszahl zwischen start und start+size
	 * @author t.loch
	 * 
	 * */
	public static double Zufallszahl(double start, double size) {
		if (size <= 0) throw new IllegalArgumentException();
		
		double sum = start + size;
		if (sum > Double.MAX_VALUE) size = Double.MAX_VALUE - start;
		
		double random = Math.random()*size;
		
		return random+start;
	}
	
	/**
	 * 
	 * generiert eine Zufallszahl
	 * 
	 * @param start ist der beginn des Intervalls und size die Groeﬂe
	 * @return eine zufallszahl zwischen start und start+size
	 * @author t.loch
	 * 
	 * */
	public static long Zufallszahl(long start, long size) {
		return Math.round(Zufallszahl((double)start, (double)size));
	}
}

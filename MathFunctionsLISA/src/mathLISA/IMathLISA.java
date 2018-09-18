package mathLISA;
import java.lang.Math;

public interface IMathLISA {

	/**
	 * 
	 * Mathematische Konstante e. Der Wert entspricht e=2.7182817
	 * 
	 * @author t.loch
	 * 
	 * */
	public static final float E = (float) Math.E;
	
	/**
	 * 
	 * Mathematische Konstante Pi. Der Wert entspricht Pi=3.1415927
	 * 
	 * @author t.loch
	 * 
	 * */
	public static final float PI = (float) Math.PI;
	
	/**
	 * 
	 * Es wird die sqrt Funktion der Mathe Bibliothek von Java verwendet um x zu berechnen.
	 * 
	 * @param x - Radikand
	 * @return Quadratwurzel von x
	 * @author t.loch
	 * 
	 * */
	public float wurzel(float x) ; // Wurzel x

	/**
	 * 
	 * Es wird die pow Funktion der Mathe Bibliothek verwendet, welche die n-te Wurzel berechnet.
	 * Dabei ist n der Nenner des Bruches im Exponenten der Potenz.
	 * 
	 * @param x - Radikand 
	 * @param n - Wurzelpotenz
	 * @return n-te Wurzel von x
	 * @author t.loch
	 * 
	 * */
	public float wurzelExp(float x, float n); // n-Wurzel von x
	
	/**
	 * 
	 * Nutzt die pow Funktion der Mathe Bibliothek von Java um x zu quadrieren.
	 * 
	 * @param x - Basis
	 * @return Quadrat von x
	 * @author t.loch
	 * 
	 * */
	public float quadrat(float x);
	
	/**
	 * 
	 * Nutzt die pow Funktion der Mathe Bibliothek von Java um x zu quadrieren.
	 * 
	 * @param x - Basis
	 * @return Quadrat von x
	 * @author t.loch
	 * 
	 * */
	public int quadrat(int x);
	
	
	/**
	 * 
	 * Nutzt die pow Funktion der Mathe Bibliothek von Java um eine Potenz mit einem beliebigen Exponenten zu berechnen.
	 * Sie entspricht der natuerlichen Exponentialfunktion.
	 * 
	 * @param x - Exponent
	 * @return Potenz von e<sup>x</sup>
	 * @author t.loch
	 * 
	 * */
	public float exp(float x);
	
	/**
	 * 
	 * Nutzt die pow Funktion der Mathe Bibliothek von Java um eine Potenz mit einem beliebigen Exponenten zu berechnen.
	 * 
	 * @param x - Basis
	 * @param y - Exponent
	 * @return Potenz von x<sup>y</sup>
	 * @author t.loch
	 * 
	 * */
	public float pot(float x, float y);
	
	/**
	 * 
	 * Nutzt die pow Funktion der Mathe Bibliothek von Java um eine Potenz mit einem beliebigen Exponenten zu berechnen.
	 * 
	 * @param x - Basis 
	 * @param y - Exponent
	 * @return Potenz von x<sup>y</sup>
	 * @author t.loch
	 * 
	 * */
	public int pot(int x, int y);
	
	/**
	 * 
	 * Nutzt die log Funktion der Mathe Bibliothek von Java um den natuerlichen Logarithmus (ln) zu berechnen.
	 * 
	 * @param x - Wurzel x zur Basis e
	 * @return Exponent von e<sup>x</sup>
	 * @author t.loch
	 * 
	 * */
	public float ln(float x);
	
	/**
	 * 
	 * Berechnet den Rest von x und y.
	 * 
	 * @param x - Zahl x
	 * @param y - Modul y
	 * @return Rest von <sup>x</sup>/<sub>y</sub>
	 * @author t.loch
	 * 
	 * */
	public int modulo(int x, int y);
	
	/**
	 * 
	 * Berechnet den Rest von x und y.
	 * 
	 * @param x - Zahl x
	 * @param y - Modul y
	 * @return Rest von <sup>x</sup>/<sub>y</sub>
	 * @author t.loch
	 * 
	 * */
	public float modulo(float x, float y);
	
	
	/**
	 * 
	 * Berechnet die Summe des angegebenen buffers.
	 * 
	 * @param values - Datenmenge
	 * @return Summe von values
	 * @author t.loch
	 * 
	 * 
	 * */
	public float sum(float[] values);
	
	/**
	 * 
	 * Berechnet das arithmetische Mittel des Buffers values.
	 * 
	 * @param values - Array von float values
	 * @return arithmetische Mittel von values
	 * @author t.loch
	 * 
	 * */
	public float durchschnitt(float[] values);
	
	/**
	 * 
	 * Berechnet die Varianz des buffers values.
	 * 
	 * @param values - Array von float values
	 * @return Varianz von values
	 * @author t.loch
	 * 
	 * */
	public float varianz(float[] values);
	
	/**
	 * 
	 * Berechnet die Standardabweichung des buffers values
	 * 
	 * @param values - Datenmenge
	 * @return Standardabweichung von values
	 * @author t.loch
	 * 
	 * */
	public float standardabw(float[] values);
	
	/**
	 * 
	 * Berechnet den Median des float arrays
	 * 
	 * @param values - Datenmenge
	 * @return median der Eingabewerte
	 * @author t.loch
	 * 
	 * */
	public float median(float[] values);
	
	/**
	 * 
	 * gibt den minimalen wert des Buffers zurueck
	 * 
	 * @param values - Datenmenge
	 * @return minimaler Wert in values
	 * @author t.loch
	 * 
	 * */
	public float min(float[] values);
	
	/**
	 * 
	 * gibt den minimalen wert des Buffers zurueck
	 * 
	 * @param values - Datenmenge
	 * @return minimaler Wert in values
	 * @author t.loch
	 * 
	 * */
	public int min(int[] values);
	
	/**
	 * 
	 * gibt den minimalen Wert von x und y zurueck durch benutzen von Math.min
	 * 
	 * @param x - Zahl
	 * @param y - Zahl
	 * @return Mnimum von x und y
	 * @author t.loch
	 * 
	 * */
	public float min(float x, float y);
	
	/**
	 * 
	 * gibt den minimalen Wert von x und y zurueck durch benutzen von Math.min
	 * 
	 * @param x - Zahl
	 * @param y - Zahl
	 * @return Mnimum von x und y
	 * @author t.loch
	 * 
	 * */
	public float min(int x, int y);
	
	/**
	 * 
	 * gibt den maximalen wert des Buffers zurueck
	 * 
	 * @param values - Datenmenge
	 * @return maximaler Wert in values
	 * @author t.loch
	 * 
	 * */
	public float max(float[] values);
	
	/**
	 * 
	 * gibt den maximalen wert des Buffers zurueck
	 * 
	 * @param values - Datenmenge
	 * @return maximaler Wert in values
	 * @author t.loch
	 * 
	 * */
	public int max(int[] values);
	
	/**
	 * 
	 * gibt den maximalen Wert von x und y zurueck durch benutzen von Math.max
	 * 
	 * @param x - Zahl
	 * @param y - Zahl
	 * @return Maximum von x und y
	 * @author t.loch
	 * 
	 * */
	public float max(float x, float y);
	
	/**
	 * 
	 * gibt den maximalen Wert von x und y zurueck durch benutzen von Math.max
	 * 
	 * @param x - Zahl
	 * @param y - Zahl
	 * @return Maximum von x und y
	 * @author t.loch
	 * 
	 * */
	public float max(int x, int y);
	
	/**
	 * 
	 * Rundet den gegebenen Wert. Bei .5 wird aufgerundet, bei kleiner .5 wird abgerundet
	 * 
	 * @param x - zu rundender Wert
	 * @return gerundeter Integer Wert von x
	 * @author t.loch
	 * 
	 * */
	public int round(float x);
	
	/**
	 * 
	 * Rundet den gegebenen Wert auf eine gegebene Nachkommastelle. Bei .5 wird aufgerundet, bei kleiner .5 wird abgerundet
	 * 
	 * @param x - zu rundende Wert 
	 * @param position - Nackommastelle auf die gerundet werden soll
	 * @return gerundeter float Wert auf die gerundete Position
	 * @author t.loch
	 * 
	 * */
	public float round(float x, int position);
	
	/**
	 * 
	 * generiert eine Zufallszahl
	 * 
	 * @param start - Beginn des Intervalls 
	 * @param size - Groeße des Intervalls
	 * @return Zufallszahl zwischen start und start+size
	 * @author t.loch
	 * 
	 * */
	public float Zufallszahl(float start, float size);
	
	/**
	 * 
	 * generiert eine Zufallszahl
	 * 
	 * @param start - Beginn des Intervalls 
	 * @param size - Groeße des Intervalls
	 * @return Zufallszahl zwischen start und start+size
	 * @author t.loch
	 * 
	 * */
	public int Zufallszahl(int start, int size);
	
	/**
	 * 
	 * gibt den Abstand von null von der eingegebenen Zahl zurück;
	 * 
	 * @param x - zu berechnende Zahl
	 * @return Abstand von 0 von x
	 * @author t.loch
	 * 
	 * */
	public int Absolut(int x);
	
	/**
	 * 
	 * gibt den Abstand von null von der eingegebenen Zahl zurück;
	 * 
	 * @param x - zu berechnende Zahl
	 * @return Abstand von 0 von x
	 * @author t.loch
	 * 
	 * */
	public float Absolut(float x);
}

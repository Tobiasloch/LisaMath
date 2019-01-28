package mathLISA;
import java.lang.Math;

import oml.basis.Lisa_Float;
import oml.basis.Lisa_Int;

public interface IMathLISA {

	/**
	 * 
	 * Mathematische Konstante e. Der Wert entspricht e=2.7182817.
	 * 
	 * @author t.loch
	 * 
	 * */
	public static final float E = (float) Math.E;
	
	/**
	 * 
	 * Mathematische Konstante e. Der Wert entspricht e=2.7182817.
	 * 
	 * @author t.loch
	 * 
	 * */
	public float getE();
	
	/**
	 * 
	 * Mathematische Konstante Pi. Der Wert entspricht Pi=3.1415927.
	 * 
	 * @author t.loch
	 * 
	 * */
	public static final float PI = (float) Math.PI;
	
	/**
	 * 
	 * Mathematische Konstante Pi. Der Wert entspricht Pi=3.1415927.
	 * 
	 * @author t.loch
	 * 
	 * */
	public float getPI();
	
	/**
	 * 
	 * Berechnet die Quadratwurzel von der Eingabe x.
	 * 
	 * @param x - Radikand
	 * @return Quadratwurzel von x
	 * @author t.loch
	 * 
	 * */
	public float wurzel(float x) ; // Wurzel x

	/**
	 * 
	 * Berechnet die n-te Wurzel der von x.
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
	 * Berechnet das Quadrat von Eingabe x.
	 * 
	 * @param x - Basis
	 * @return Quadrat von x
	 * @author t.loch
	 * 
	 * */
	public float quadrat(float x);
	
	/**
	 * 
	 * Berechnet das Quadrat von Eingabe x.
	 * 
	 * @param x - Basis
	 * @return Quadrat von x
	 * @author t.loch
	 * 
	 * */
	public int quadrat(int x);
	
	
	/**
	 * 
	 * Berechnet den Wert der natürlichen Exponentialfunktion von der Eingabe x.
	 * 
	 * @param x - Exponent
	 * @return Potenz von e<sup>x</sup>
	 * @author t.loch
	 * 
	 * */
	public float exp(float x);
	
	/**
	 * 
	 * Berechnet die Potenz x<sup>y</sup>.
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
	 * Berechnet die Potenz x<sup>y</sup>.
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
	 * Berechnet den Wert des natürlichen Logarithmus an der Stelle x.
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
	 * Berechnet die Summe der angegebenen Werte.
	 * 
	 * @param values - Datenmenge
	 * @return Summe von values
	 * @author t.loch
	 * 
	 * 
	 * */
	public float sum(Lisa_Float[] values);
	
	/**
	 * 
	 * Berechnet das arithmetische Mittel der Werte.
	 * 
	 * @param values - Array von float values
	 * @return arithmetische Mittel von values
	 * @author t.loch
	 * 
	 * */
	public float durchschnitt(Lisa_Float[] values);
	
	/**
	 * 
	 * Berechnet die Varianz der angegebenen Werte.
	 * 
	 * @param values - Array von float values
	 * @return Varianz von values
	 * @author t.loch
	 * 
	 * */
	public float varianz(Lisa_Float[] values);
	
	/**
	 * 
	 * Berechnet die Standardabweichung der angegebenen Werte.
	 * 
	 * @param values - Datenmenge
	 * @return Standardabweichung von values
	 * @author t.loch
	 * 
	 * */
	public float standardabw(Lisa_Float[] values);
	
	/**
	 * 
	 * Berechnet den Median der angegebenen Werte.
	 * 
	 * @param values - Datenmenge
	 * @return median der Eingabewerte
	 * @author t.loch
	 * 
	 * */
	public float median(Lisa_Float[] values);
	
	/**
	 * 
	 * Berechnet den minimalen Wert der angegebenen Werte.
	 * 
	 * @param values - Datenmenge
	 * @return minimaler Wert in values
	 * @author t.loch
	 * 
	 * */
	public float min(Lisa_Float[] values);
	
	/**
	 * 
	 * Berechnet den minimalen Wert der angegebenen Werte.
	 * 
	 * @param values - Datenmenge
	 * @return minimaler Wert in values
	 * @author t.loch
	 * 
	 * */
	public int min(Lisa_Int[] values);
	
	/**
	 * 
	 * Berechnet den minimalen Wert der angegebenen Werte x und y.
	 * 
	 * @param x - Zahl
	 * @param y - Zahl
	 * @return Mnimum von x und y
	 * @author t.loch
	 * 
	 * */
	public float minAtomar(float x, float y);
	
	/**
	 * 
	 * Berechnet den minimalen Wert der angegebenen Werte x und y.
	 * 
	 * @param x - Zahl
	 * @param y - Zahl
	 * @return Mnimum von x und y
	 * @author t.loch
	 * 
	 * */
	public float minAtomar(int x, int y);
	
	/**
	 * 
	 * Berechnet den maximalen Wert der angegebenen Werte.
	 * 
	 * @param values - Datenmenge
	 * @return maximaler Wert in values
	 * @author t.loch
	 * 
	 * */
	public float max(Lisa_Float[] values);
	
	/**
	 * 
	 * Berechnet den maximalen Wert der angegebenen Werte.
	 * 
	 * @param values - Datenmenge
	 * @return maximaler Wert in values
	 * @author t.loch
	 * 
	 * */
	public int max(Lisa_Int[] values);
	
	/**
	 * 
	 * Berechnet den maximalen Wert der angegebenen Werte x und y.
	 * 
	 * @param x - Zahl
	 * @param y - Zahl
	 * @return Maximum von x und y
	 * @author t.loch
	 * 
	 * */
	public float maxAtomar(float x, float y);
	
	/**
	 * 
	 * Berechnet den maximalen Wert der angegebenen Werte x und y.
	 * 
	 * @param x - Zahl
	 * @param y - Zahl
	 * @return Maximum von x und y
	 * @author t.loch
	 * 
	 * */
	public float maxAtomar(int x, int y);
	
	/**
	 * 
	 * Rundet den gegebenen Wert. Bei .5 wird aufgerundet, bei kleiner .5 wird abgerundet.
	 * 
	 * @param x - zu rundender Wert
	 * @return gerundeter Integer Wert von x
	 * @author t.loch
	 * 
	 * */
	public int round(float x);
	
	/**
	 * 
	 * Rundet den gegebenen Wert auf eine gegebene Nachkommastelle. Bei .5 wird aufgerundet, bei kleiner .5 wird abgerundet.
	 * 
	 * @param x - zu rundende Wert 
	 * @param position - Nackommastelle auf die gerundet werden soll
	 * @return gerundeter float Wert auf die gerundete Position
	 * @author t.loch
	 * 
	 * */
	public float roundPosition(float x, int position);
	
	/**
	 * 
	 * Generiert eine Zufallszahl.
	 * 
	 * @param start - Beginn des Intervalls 
	 * @param size - Groe�e des Intervalls
	 * @return Zufallszahl zwischen start und start+size
	 * @author t.loch
	 * 
	 * */
	public float Zufallszahl(float start, float size);
	
	/**
	 * 
	 * Generiert eine Zufallszahl.
	 * 
	 * @param start - Beginn des Intervalls 
	 * @param size - Groe�e des Intervalls
	 * @return Zufallszahl zwischen start und start+size
	 * @author t.loch
	 * 
	 * */
	public int Zufallszahl(int start, int size);
	
	/**
	 * 
	 * Berechnet den Betrag, also den Abstand von 0, der gegebenen Zahl.
	 * 
	 * @param x - zu berechnende Zahl
	 * @return Abstand von 0 von x
	 * @author t.loch
	 * 
	 * */
	public int Absolut(int x);
	
	/**
	 * 
	 * Berechnet den Betrag, also den Abstand von 0, der gegebenen Zahl.
	 * 
	 * @param x - zu berechnende Zahl
	 * @return Abstand von 0 von x
	 * @author t.loch
	 * 
	 * */
	public float Absolut(float x);
}

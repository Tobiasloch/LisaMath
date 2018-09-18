package Test;

import static org.junit.Assert.*;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

import org.junit.BeforeClass;
import org.junit.Test;

import mathLISA.*;

public class MathLISATest {

	public static final int numberOfTests = 100;
	public static final int roundFactor = 4; // Rundungsfaktor	
	public static final int maxSquare = 10;
	public static final float Accuracy = (float) 0.0001;

	// ungerade indizes sind die eingabewertarrays; gerade indizes sind die Zwischenergebnisse
	public static final float[][] DEFAULT_standardabwTestData = {{8, 7, 9, 10, 6}, {40, 8, 2, (float) 1.4142135623730951}, 
			{5,10,-10,9,-55,8,6}, {-27, (float) -3.8571, (float) 475.2653, (float) 21.80058041},
			{10, 10}, {20, 10, 0, 0},
			{5,6}, {11, (float) 5.5, (float) 0.25, (float) 0.5},
			{15,16,15,17}, {63, (float) 15.75, (float) 0.6875, (float) 0.829156198},
			{(float) 5.5, 1, (float) 2.68, (float) 0.001}, {(float) 9.181, (float) 2.29525, (float) 4.3399, (float) 2.0832}};
	
	public static final float[][] DEFAULT_medianTestData = {{5, 3, 7, 4, 4, 3, 6, 4, 7, 8, 7, 6}, {(float) 5.5}
			};
	
	// jeder zweite wert ist das ergebnis und besteht aus der gerundeten Stelle und dem ergebniswert
	public static final float[][] DEFAULT_roundTestData = {{(float) 5.54556}, {2, (float) 5.55},
			{(float) 15.21353}, {3, (float) 15.214},
			{(float) 15.1}, {3, (float) 15.1},
			{(float) -0.1111}, {1, (float) -0.1},
			{(float) -0.6}, {0, -1},
			{(float) 5.93}, {0, 6}};
	
	public static final File DEFAULT_TEST_FOLDER = new File("./src/Test/TestFolder");
	public static final String[] DATA_FILE_NAMES = {"StandardabwTest", "medianTest", "roundTest"};
	public static final String DATA_FILE_EXTENSION = "test";
	public static final String DATA_VAR_NAME = "test";
	
	public static float[][] standardabwTestData = DEFAULT_standardabwTestData;
	public static float[][] medianTestData = DEFAULT_medianTestData;
	public static float[][] roundTestData = DEFAULT_roundTestData;
	
	MathLISAImpl maLi = new MathLISAImpl(null);
	
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		File folder = DEFAULT_TEST_FOLDER;
		
		File[] dataFiles = new File[DATA_FILE_NAMES.length];
		for (int i = 0; i < dataFiles.length; i++) dataFiles[i] = new File(folder + File.separator + DATA_FILE_NAMES[i] + "." + DATA_FILE_EXTENSION);

		standardabwTestData = readDataFromStringIntoArray(fileToString(dataFiles[0]));
		medianTestData = readDataFromStringIntoArray(fileToString(dataFiles[1]));
		roundTestData = readDataFromStringIntoArray(fileToString(dataFiles[2]));
	}
	
	public static void saveArray(float[][] array, File f) {
		JSONObject jObject = new JSONObject();
		try {
			jObject.put(DATA_VAR_NAME, array);
			FileWriter fr = new FileWriter(f);
			fr.write(jObject.toString());
			fr.close();
		} catch (JSONException | IOException e) {
			e.printStackTrace();
		}
		
		
	}
	
	public static float[][] readDataFromStringIntoArray(String s) {
		float[][] array = null;
		
		try {
			JSONObject jObject =  new JSONObject(s);
			JSONArray jArray = jObject.getJSONArray(DATA_VAR_NAME);
			
			array = new float[jArray.length()][];
			for (int i = 0; i < jArray.length(); i++) {
				JSONArray internalArray = jArray.getJSONArray(i);
				
				array[i] = new float[internalArray.length()];
				for (int k = 0; k < internalArray.length(); k++) {
					array[i][k] = (float) internalArray.getDouble(k);
				}
			}
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return array;
	}
	
	public static String fileToString(File f) {
		if (!f.exists()) return "";
		
		String text = "";
		try (BufferedReader br = new BufferedReader(new FileReader(f));) {
			String line;
			while ((line = br.readLine()) != null) {
				text += line;
			}
		} catch (IOException e1) {
			e1.printStackTrace();
		}

		return text;
	}
	
	@Test
	public void WurzelTest() {
		for (int i = 0; i < numberOfTests; i++) {
			Random r = new Random();
			float y = (float) r.nextFloat() * numberOfTests;
			
			float expected = maLi.round((float)Math.sqrt(y), roundFactor);
			float actual = maLi.round(maLi.wurzel(y), roundFactor);
			assertTrue("The square is wrong! expected: " + expected + ", but was " + actual, expected == actual);
			
			int rad = r.nextInt(maxSquare)+1;
			
			expected = maLi.round(y, roundFactor);
			actual = maLi.round(maLi.wurzelExp((float)Math.pow(expected, rad), rad), roundFactor);

			assertTrue("The square is wrong! expected: " + expected + ", but was " + actual, Math.abs(expected-actual) < Accuracy);
		}
		
		// test wrong params
		float[] wrongParams = {-1, Float.POSITIVE_INFINITY, Float.NaN};
		
		for (float x : wrongParams) {
			try {
				float result = maLi.wurzel(x);
				fail("The wurzel function did not throw an excepction! result: " + result + "; parameter: " + x);
			} catch (IllegalArgumentException ia) {
				
			}
		}
	}
	
	@Test
	public void PotenzTester() {
		for (int i = 0; i < numberOfTests; i++) {
			Random r = new Random();
			float y = (r.nextFloat() * numberOfTests) - (numberOfTests/2);
			int rad = r.nextInt(maxSquare)+1;
			
			// test float version of quadrat
			float fExpected = maLi.round((float)Math.pow(y,2), roundFactor);
			float fActual = maLi.round(maLi.quadrat(y), roundFactor);
			assertTrue("The float quadrat is wrong! expected: " + fExpected + ", but was " + fActual, fExpected == fActual);
			
			// test int version of quadrat
			int iExpected = (int) Math.pow((int)y,2);
			int iActual = maLi.quadrat((int) y);
			assertTrue("The int quadrat is wrong! expected: " + iExpected + ", but was " + iActual, iExpected == iActual);
			
			fExpected = maLi.round(Math.abs(y), roundFactor);
			fActual = maLi.round(maLi.pot((float)maLi.wurzelExp(fExpected, rad), rad), roundFactor);
			assertTrue("The quadrat is wrong! expected: " + fExpected + ", but was " + fActual, Math.abs(fExpected-fActual) <= Accuracy);
		}
		
		// test wrong params
		float[] wrongParams = {Float.POSITIVE_INFINITY, Float.NaN};
		
		for (float x : wrongParams) {
			try {
				float result = maLi.wurzel(x);
				fail("The wurzel function did not throw an excepction! result: " + result + "; parameter: " + x);
			} catch (IllegalArgumentException ia) {
				
			}
		}

	}
	
	@Test
	public void logTest() {
		for (int i = 0; i < numberOfTests; i++) {
			Random r = new Random();
			float y = r.nextFloat() * numberOfTests;
			
			float expected = (float) Math.log(y);
			float actual = maLi.ln(y);
			
			assertTrue("The ln function is wrong! expected: " + expected + ", but was " + actual, Math.abs(Math.abs(expected) - Math.abs(actual)) <= Accuracy);
		}
		
		// test errors
		float[] wrongParams = {-1, 0, Float.POSITIVE_INFINITY, Float.NaN};
		
		for (float x : wrongParams) {
			try {
				float result = maLi.ln(x);
				fail("The ln function did not throw an excepction! result: " + result + "; parameter: " + x);
			} catch (IllegalArgumentException ia) {
				
			}
		}
	}
	
	@Test
	public void moduloTest() {
		for (int i = 0; i < numberOfTests; i++) {
			Random r = new Random();
			float x = (r.nextFloat() * numberOfTests) - (numberOfTests/2);
			float y = (r.nextFloat() * numberOfTests * 2) - (numberOfTests);
			if ((int)x==0) x+=2;
			
			double expected = y%x;
			double actual = maLi.modulo(y, x);
			 
			assertTrue("The modulo function is wrong! expected: " + expected + ", but was " + actual, Math.abs(Math.abs(expected) - Math.abs(actual)) <= Accuracy);
			
			expected = ((int)y%(int)x);
			actual = maLi.modulo((int)y,(int)x);
			
			assertTrue("The modulo function is wrong! expected: " + expected + ", but was " + actual, expected == actual);
		}
		
		// test errors
		float[] wrongParams = {0, Float.POSITIVE_INFINITY, Float.NaN};
		
		for (float x : wrongParams) {
			try {
				float result = maLi.modulo(x, x);
				fail("The modulo function did not throw an excepction! result: " + result + "; parameter: " + x);
			} catch (IllegalArgumentException ia) {
				
			}
		}
	}
	
	@Test
	public void RandomTest() {
		for (int i = 0; i < numberOfTests; i++) {
			Random r = new Random();
			int x = r.nextInt();
			int y = Math.abs(r.nextInt());

			float start = x;
			float end = (float)x + (float)y;
			
			int random = maLi.Zufallszahl(x, y);
			
			try {
				assertTrue("random: "+ random + "  \nstart: "+start + "  \nend: "+ end + "  \nPosition: " + i + "\nsize: "+y, (random >= start) && (random <= end));
			} catch (IllegalArgumentException e) {
				fail("The size is smaller or equals than 0! size: " + y + "; start: " + x);
				
				e.printStackTrace();
			}
		}
	}
	
	@Test
	public void StandardabwTest() {
		float[][] values = standardabwTestData;
		
		for (int i = 0; i<values.length; i+=2) { 
			float[] results = values[i+1];
			for (int k = 0; k < results.length; k++) results[k] = maLi.round(results[k], roundFactor);

			float sum = maLi.round(maLi.sum(values[i]), roundFactor);
			float durch = maLi.round(maLi.durchschnitt(values[i]), roundFactor);
			float var = maLi.round(maLi.varianz(values[i]), roundFactor);
			float std = maLi.round(maLi.standardabw(values[i]), roundFactor);
			
			assertTrue("sum was " + sum + " but expected was" + results[0], sum == results[0]);
			assertTrue("durchschnitt was " + durch + " but expected was " + results[1], durch == results[1]);
			assertTrue("varianz was " + results[2] + " but expected was " + var, var == results[2]);
			assertTrue("std was " + std + " but expected was " + results[3], std == results[3]);
		}
	}
	
	@Test
	public void medianTest() {
		float[][] values = medianTestData;
		
		for (int i = 0; i < values.length; i+=2) {
			float[] results = values[i+1];
			
			float median = maLi.round(maLi.median(values[i]), roundFactor);
			
			results[0] = maLi.round(results[0], roundFactor);
			assertTrue("median is " + median + " but expected was " + results[0], median == results[0]);
		}
	}
	@Test
	public void roundTest() {
		float[][] values = roundTestData;
		
		for (int i = 0; i < values.length; i+=2) {
			float[] results = values[i+1];
			
			float round = maLi.round(values[i][0], (int)results[0]);
			
			assertTrue("Values was rounded incorrect! expected: " + results[1] + ", but was: " + round, round == results[1]);
		}
		
	}
	
	@Test
	public void minMaxTest() {
		int arraySize = (int) maLi.Zufallszahl(2, numberOfTests/2);
		
		int[] array = new int[arraySize];
		int maxArray = 0;
		int minArray = 0;
		
		for (int i = 0; i < numberOfTests; i++) {
			Random r = new Random();
			
			int x = Math.abs(r.nextInt());
			int y = Math.abs(r.nextInt());
			int min = Math.min(x, y);
			int max = Math.max(x, y);
			
			assertTrue("The min value of " + x + ", " + y + " is " + maLi.min(x, y) + ", but expected was " + min, min == maLi.min(x, y));
			assertTrue("The max value of " + x + ", " + y + " is " + maLi.max(x, y) + ", but expected was " + max, max == maLi.max(x, y));
			
			if (i%arraySize == 0) {
				array = new int[arraySize];
				maxArray = 0;
				minArray = 0;
			} else {
				array[i%arraySize] = x;
				
				maxArray = Math.max(maxArray, x);
				minArray = Math.min(minArray, x);

				assertTrue("The max value of the array is " + maLi.max(array) + ", but expected was " + maxArray, maxArray == maLi.max(array));
				assertTrue("The min value of the array is " + maLi.min(array) + ", but expected was " + minArray, minArray == maLi.min(array));
			}
		}
	}
	
}

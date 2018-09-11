package Test;

import classes.*;
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

public class MathLISATest {

	public static final int numberOfTests = 1000;
	public static final int roundFactor = 4; // Rundungsfaktor	

	// ungerade indizes sind die eingabewertarrays; gerade indizes sind die Zwischenergebnisse
	public static final double[][] DEFAULT_standardabwTestData = {{8, 7, 9, 10, 6}, {40, 8, 2, 1.4142135623730951}, 
			{5,10,-10,9,-55,8,6}, {-27, -3.8571, 475.2653, 21.80058041},
			{10, 10}, {20, 10, 0, 0},
			{5,6}, {11, 5.5, 0.25, 0.5},
			{15,16,15,17}, {63, 15.75, 0.6875, 0.829156198},
			{5.5, 1, 2.68, 0.001}, {9.181, 2.29525, 4.3399, 2.0832}};
	
	public static final double[][] DEFAULT_medianTestData = {{5, 3, 7, 4, 4, 3, 6, 4, 7, 8, 7, 6}, {5.5}
			};
	// jeder zweite wert ist das ergebnis und besteht aus der gerundeten Stelle und dem ergebniswert
	public static final double[][] DEFAULT_roundTestData = {{5.54556}, {2, 5.55},
			{15.21353}, {3, 15.214},
			{15.1}, {3, 15.1},
			{-0.1111}, {1, -0.1},
			{-0.6}, {0, -1},
			{5.93}, {0, 6}};
	
	public static final File DEFAULT_TEST_FOLDER = new File("./src/Test/TestFolder");
	public static final String[] DATA_FILE_NAMES = {"StandardabwTest", "medianTest", "roundTest"};
	public static final String DATA_FILE_EXTENSION = "test";
	public static final String DATA_VAR_NAME = "test";
	
	public static double[][] standardabwTestData = DEFAULT_standardabwTestData;
	public static double[][] medianTestData = DEFAULT_medianTestData;
	public static double[][] roundTestData = DEFAULT_roundTestData;

	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		File folder = DEFAULT_TEST_FOLDER;
		
		File[] dataFiles = new File[DATA_FILE_NAMES.length];
		for (int i = 0; i < dataFiles.length; i++) dataFiles[i] = new File(folder + File.separator + DATA_FILE_NAMES[i] + "." + DATA_FILE_EXTENSION);

		standardabwTestData = readDataFromStringIntoArray(fileToString(dataFiles[0]));
		medianTestData = readDataFromStringIntoArray(fileToString(dataFiles[1]));
		roundTestData = readDataFromStringIntoArray(fileToString(dataFiles[2]));
	}
	
	public static void saveArray(double[][] array, File f) {
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
	
	public static double[][] readDataFromStringIntoArray(String s) {
		double[][] array = null;
		
		try {
			JSONObject jObject =  new JSONObject(s);
			JSONArray jArray = jObject.getJSONArray(DATA_VAR_NAME);
			
			array = new double[jArray.length()][];
			for (int i = 0; i < jArray.length(); i++) {
				JSONArray internalArray = jArray.getJSONArray(i);
				
				array[i] = new double[internalArray.length()];
				for (int k = 0; k < internalArray.length(); k++) {
					array[i][k] = internalArray.getDouble(k);
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
		FileReader fr;
		try {
			fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			
			String line;
			while ((line = br.readLine()) != null) {
				text += line;
			}
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}

		return text;
	}
	
	@org.junit.Test
	public void RandomTest() {
		for (int i = 0; i < numberOfTests; i++) {
			Random r = new Random();
			long x = r.nextLong();
			long y = Math.abs(r.nextLong());
			
			double start = x;
			double end = (double)x + (double)y;
			
			long random = MathLISA.Zufallszahl(x, y);
			
			assertTrue("random: "+ random + "  \nstart: "+start + "  \nend: "+ end + "  \nPosition: " + i + "\nsize: "+y, (random >= start) && (random <= end));
		}
	}
	
	@org.junit.Test
	public void StandardabwTest() {
		double[][] values = standardabwTestData;
		
		for (int i = 0; i<values.length; i+=2) { 
			double[] results = values[i+1];
			for (int k = 0; k < results.length; k++) results[k] = MathLISA.round(results[k], roundFactor);

			double sum = MathLISA.round(MathLISA.sum(values[i]), roundFactor);
			double durch = MathLISA.round(MathLISA.durchschnitt(values[i]), roundFactor);
			double var = MathLISA.round(MathLISA.varianz(values[i]), roundFactor);
			double std = MathLISA.round(MathLISA.standardabw(values[i]), roundFactor);
			
			assertTrue("sum was " + sum + " but expected was" + results[0], sum == results[0]);
			assertTrue("durchschnitt was " + durch + " but expected was " + results[1], durch == results[1]);
			assertTrue("varianz was " + results[2] + " but expected was " + var, var == results[2]);
			assertTrue("std was " + std + " but expected was " + results[3], std == results[3]);
		}
	}
	
	@org.junit.Test
	public void medianTest() {
		double[][] values = medianTestData;
		
		for (int i = 0; i < values.length; i+=2) {
			double[] results = values[i+1];
			
			double median = MathLISA.round(MathLISA.median(values[i]), roundFactor);
			
			results[0] = MathLISA.round(results[0], roundFactor);
			assertTrue("median is " + median + " but expected was " + results[0], median == results[0]);
		}
	}
	@org.junit.Test
	public void roundTest() {
		double[][] values = roundTestData;
		
		for (int i = 0; i < values.length; i+=2) {
			double[] results = values[i+1];
			
			double round = MathLISA.round(values[i][0], (int)results[0]);
			
			assertTrue("Values was rounded incorrect! expected: " + results[1] + ", but was: " + round, round == results[1]);
		}
		
	}
	
	@org.junit.Test
	public void minMaxTest() {
		int arraySize = (int) MathLISA.Zufallszahl(2, numberOfTests/2);
		
		long[] array = new long[arraySize];
		long maxArray = 0;
		long minArray = 0;
		
		for (int i = 0; i < numberOfTests; i++) {
			Random r = new Random();
			
			long x = Math.abs(r.nextLong());
			long y = Math.abs(r.nextLong());
			long min = Math.min(x, y);
			long max = Math.max(x, y);
			
			assertTrue("The min value of " + x + ", " + y + " is " + MathLISA.min(x, y) + ", but expected was " + min, min == MathLISA.min(x, y));
			assertTrue("The max value of " + x + ", " + y + " is " + MathLISA.max(x, y) + ", but expected was " + max, max == MathLISA.max(x, y));
			
			if (i%arraySize == 0) {
				array = new long[arraySize];
				maxArray = 0;
				minArray = 0;
			} else {
				array[i%arraySize] = x;
				
				maxArray = Math.max(maxArray, x);
				minArray = Math.min(minArray, x);

				assertTrue("The max value of the array is " + MathLISA.max(array) + ", but expected was " + maxArray, maxArray == MathLISA.max(array));
				assertTrue("The min value of the array is " + MathLISA.min(array) + ", but expected was " + minArray, minArray == MathLISA.min(array));
			}
		}
	}
	
}

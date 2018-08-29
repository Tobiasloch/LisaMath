package Test;

import classes.*;
import static org.junit.Assert.*;

import java.util.Random;

public class Test {

public static final int numberOfTests = 1000;
	
	@org.junit.Test
	public void RandomTest() {
		for (int i = 0; i < numberOfTests; i++) {
			Random r = new Random();
			long x = r.nextLong();
			long y = Math.abs(r.nextLong());
			
			double start = x;
			double end = (double)x+ (double)y;
			
			long random = MathLISA.Zufallszahl(x, y);
			
			assertTrue("random: "+random + "  \nstart: "+start + "  \nend: "+ end + "  \nPosition: " + i + "\nsize: "+y, (random >= start) && (random <= end));
		}
	}
	
	@org.junit.Test
	public void StandardabwTest() {
		double values[] = new double[] {8, 7, 9, 10, 6};
		
		double sum = MathLISA.sum(values);
		double durch = MathLISA.durchschnitt(values);
		double var = MathLISA.varianz(values);
		double std = MathLISA.standardabw(values);
		
		assertTrue("sum was " + sum + " but expected was" + 40, sum == 40);
		assertTrue("durchschnitt was " + durch + " but expected was " + 8, durch == 8);
		assertTrue("expected was " + 2 + " but vlaue is " + var, 2 == var);
		assertTrue("std was " + std + " but expected was " + Math.sqrt(2), std == Math.sqrt(2));
	}
	
	@org.junit.Test
	public void medianTest() {
		double[] values = new double[] {5, 3, 7, 4, 4, 3, 6, 4, 7, 8, 7, 6};
		
		double median = MathLISA.median(values);
		assertTrue("median is " + median + " but expected was " + 5.5, median == 5.5);
	}
	@org.junit.Test
	public void roundTest() {
		double x = 15.21353;
		double round = MathLISA.round(x, 3);
		assertTrue("", round == 15.214);
		
	}
	
}

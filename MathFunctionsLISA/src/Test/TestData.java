package Test;

import java.io.File;
import java.io.IOException;

import com.fasterxml.jackson.databind.ObjectMapper;

public class TestData <T> {
	
	public static final String[] DATA_FILE_NAMES = {"StandardabwTest", "medianTest", "roundTest"};
	public static final File DEFAULT_TEST_FOLDER = new File("./src/Test/TestFolder");
	
	public T[] data;
	
	public static void main(String args[]) {
		TestResult<Double> r = new TestResult<Double>();
		Double[] l = new Double[] { (Double) 5.5};
		r.result = l;
		
		r.saveResult(new File(TestData.DEFAULT_TEST_FOLDER + "/test.test"));
	}
	
	public void saveData(File file) {
		ObjectMapper objectMapper = new ObjectMapper();
		
		if (file.exists()) throw new IllegalArgumentException("File already exists! path: " + file);
		
		try {
			objectMapper.writeValue(file, this);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	@Override
	public String toString() {
		String s = "";
		for (T element : data) s+= element + "\n";
		
		return s;
	}
}

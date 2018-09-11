package Test;

import java.io.File;
import java.io.IOException;

import com.fasterxml.jackson.databind.ObjectMapper;

public class TestResult<T> {
	
	public T[] result;
	
	public static void main(String args[]) {
		TestResult<Long> r = new TestResult<Long>();
		Long[] l = new Long[] { (long) 5, (long) 3, (long) 7,(long) 4,(long) 4,(long) 3,(long) 6,(long) 4,(long) 7,(long) 8,(long) 7,(long) 6};
		r.result = l;
		
		r.saveResult(new File(TestData.DEFAULT_TEST_FOLDER + "/test.res"));
	}
	
	public void saveResult(File file) {
		ObjectMapper objectMapper = new ObjectMapper();
		
		if (file.exists()) throw new IllegalArgumentException("File already exists! path: " + file);
		
		try {
			objectMapper.writeValue(file, this);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

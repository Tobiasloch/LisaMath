package Test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

import com.fasterxml.jackson.databind.ObjectMapper;

public class Tests<T1, T2> {
	
	public static final File TEST_DATA_FOLDER = new File("./src/test/resources/testData");
	
	public static final String TEST_FILE_EXTENSION = "test";
	public static final String RESULT_FILE_EXTENSION = "res";
	public static final String ZIP_FILE_EXTENSION = "zip";
	
	public static final String EXTENSION_REMOVE_REGEX = "[.][^.]+$";
	
	private TestData<T1> testData;
	private TestData<T2> testResult;
	
	private File file;
	
	public Tests(File file) {
		loadDataFromZipFile(file);
	}
	
	public Tests() {
		
	}
	
	public static void main(String[] args) {
		Tests<Long, Double> t = new Tests<Long, Double>(new File("U:\\Mathe Funktionen\\MathFunctionsLISA\\src\\Test\\TestFolder\\TestFolder.zip"));
		
		System.out.println(t.testData);
		System.out.println(t.testResult);
	}
	
	public void loadDataFromZipFile(File file) {
		this.file = file;
		
		// error handling
		if (!file.exists()) throw new IllegalArgumentException("The file does not Exist");
		if (!getFileNameExtension(file.getName()).equals(ZIP_FILE_EXTENSION)) 
			System.err.println("The file does not have a zip file extension! (." + 
								ZIP_FILE_EXTENSION + ")");
		
		InputStream fStream;
		try {
			fStream = new FileInputStream(file);
			ZipInputStream zipStream = new ZipInputStream(fStream);
			
			// goes through the enrys and searches for the result and test files
			ZipEntry entry;
			String oplFileName = "";
			while((entry = zipStream.getNextEntry()) != null) { // runs aslong a entry is existing
				String extension = getFileNameExtension(entry.getName());
				
				if (extension.equals(TEST_FILE_EXTENSION)) {
					importData(zipStream);
					break;
				}
			}
			if (oplFileName.equals("")) 
				throw new IllegalArgumentException("No File with extension " + TEST_FILE_EXTENSION + " has been found!");
				
			fStream = new FileInputStream(file);
			zipStream = new ZipInputStream(fStream);
			while((entry = zipStream.getNextEntry()) != null) {
				String extension = getFileNameExtension(entry.getName());
				String name = entry.getName().replaceFirst(EXTENSION_REMOVE_REGEX, "");
				
				if (extension.equals(RESULT_FILE_EXTENSION) && name.equals(oplFileName)) {
					importResult(zipStream);
					break;
				}
			}
			
			if (testResult == null) 
				throw new IllegalArgumentException("No file with extension " + RESULT_FILE_EXTENSION + " has been found!");

		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void importResult(InputStream iStream) {
		StringBuilder text = new StringBuilder();
	
		BufferedReader br = new BufferedReader(new InputStreamReader(iStream));
		
		try {
			String line;
			while ((line = br.readLine()) != null) {
				text.append(line);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

		importResult(text.toString());
		
	}
	
	public void importResult(String object) {
		ObjectMapper objectMapper = new ObjectMapper();
		
		try {
			testResult = objectMapper.readValue(object, TestData.class);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void importData(InputStream iStream) {
		StringBuilder text = new StringBuilder();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(iStream));
		
		try {
			String line;
			while ((line = br.readLine()) != null) {
				text.append(line);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

		importData(text.toString());
	}
	
	@SuppressWarnings("unchecked")
	public void importData(String object) {
		ObjectMapper objectMapper = new ObjectMapper();

		try {
			testData = objectMapper.readValue(object, TestData.class);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static String getFileNameExtension(String name) {
		String extension = "";
		
		int i = name.lastIndexOf(".");
		if (i>0) {
			extension = name.substring(i+1);
		}
		
		return extension;
	}
	
	public static List<Tests> getTestsFromFolder(File folder, boolean rekursive) {
		List<Tests> tests = new ArrayList<Tests>();
		List<File> files = getSubfiles(folder, rekursive);
			
		for (File f : files) {
			if (getFileNameExtension(f.getName()).equals(ZIP_FILE_EXTENSION)) {
				Tests test = new Tests(f);
				
				tests.add(test);
			}
		}
		
		return tests;
	}
	
	public static List<File> getSubfiles(File folder, boolean rekursive) {
		if (!folder.isDirectory()) throw new IllegalArgumentException("The given file object is not a Folder! path: " + folder);
		String[] fileNames = folder.list();
		List<File> files = new ArrayList<File>();
		
		for (String s : fileNames) {
			File f = new File(folder.getPath() + File.separator + s);
			files.add(f);
			
			if (rekursive && f.isDirectory()) {
				files.addAll(getSubfiles(f, rekursive));
			}
		}
		
		return files;
	}
	
	public TestData<T2> getTestResult() {
		return testResult;
	}

	public TestData<T1> getTestData() {
		return testData;
	}

	public File getFile() {
		return file;
	}
}

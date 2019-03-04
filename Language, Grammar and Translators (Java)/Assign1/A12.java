import java.nio.file.*;
import java.util.*;
import java.util.regex.*;
public class A12 {
	public static void main(String[] args)throws Exception
	{
		Set<String>identifiers=new HashSet<>();	
		String textFile=new String(Files.readAllBytes(Paths.get("args[0]"))).replaceAll("\".*\"zWRITEzREADzIFzELSEzRETURNzBEGINzENDzMAINzSTRINGzINTzREAL".replaceAll("z", "|"), " ");
		Matcher m1=Pattern.compile("[a-zA-Z][a-zA-Z0-9]*").matcher(textFile);
		while(m1.find())
			identifiers.add(m1.group());
		Files.write(Paths.get("A1.output"), ("identifiers:"+identifiers.size()).getBytes());
	}
}

import java.io.*;
import java.nio.file.*;
import java.util.*;

public class A11 
{
	
	public static void main(String args[]) throws Exception
	{
		
		ArrayList<String>identifierList=new ArrayList<>(Arrays.asList("WRITE","READ","IF","ELSE","RETURN","BEGIN","END","MAIN","STRING","INT","REAL"));
	 	ArrayList<String>identifiers=new ArrayList<>();
		
		BufferedReader br=new BufferedReader(new FileReader("args[0]"));
		
		String line=br.readLine()+'\n';
		String str="";
		
		do 
		{
			
			boolean inQuotes=false;
			
			for(int i=0; i<line.length();i++) 
			{
				char c=line.charAt(i);
					
				if(c<=122&&c>=97||c>= 65 && c <= 90)
				{
					if(!inQuotes)
						str+=c;
				}
				else if(Character.isDigit(c))
				{
					if(str!=""&&!inQuotes)
						str+=c;
				}
				else if(c=='"')
				{
					if(str != "" &! identifierList.contains(str)&!identifiers.contains(str)) 
						identifiers.add(str); 
					
					if(inQuotes) str="";
					inQuotes=!inQuotes;
				}
				else 
				{
					if(str != "" &! identifierList.contains(str)&!identifiers.contains(str)) 
						identifiers.add(str); 
					str = "";
				}
				
				if(line.charAt(i+1)=='\n')
				{
					if(str!=""&!identifierList.contains(str)&!identifiers.contains(str))  
						identifiers.add(str); 	
					str="";
					break;
				}
			}
			line = br.readLine() + '\n';
		}while(br.ready());
		
		br.close();
		
		if(str!="") { 
			if(!identifierList.contains(str)&!identifiers.contains(str)) 
				identifiers.add(str); 
		}
		
		Files.write(Paths.get("A1.output"), ("identifiers:"+identifiers.size()).getBytes());

	}
	
}

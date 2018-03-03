//http://www.spoj.com/problems/JAVAC/

import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static boolean containsSeparators(String name){
        if(name.trim().indexOf("")>=0 || name.indexOf("-") >=0){
            return false;
        }
        return true;
    }

    public static boolean isJavaName(String name){
        //if it contains underscore or starts with capital letter it is not a java name
        if(name.indexOf("_")>=0 || name.charAt(0)<='Z' || containsSeparators(name)){
            return false;
        }
        return true;
    }

    public static boolean isCname(String name){
        if(name.chars().filter(p->p<91).sum()!=0) return false; //if contains upper case characters it is not a C
        if(name.charAt(0) == '_') return false; //if starts with _ also error
        while(name.contains("_")){
            if(name.indexOf("_")==name.length()-1) return false;
            if(name.charAt(name.indexOf("_")+1)=='_' || name.charAt(name.indexOf("_"))==name.length()-1) {
                return false;
            }
            name = name.substring(name.indexOf("_")+1,name.length());
        }
        return true;
    }

    public static String convertToJava(String name){
        String [] words = name.replaceAll("_"," ").split(" ");
        for(int i=1;i<words.length;i++){
            words[i] = Character.toUpperCase(words[i].charAt(0))+words[i].substring(1);
        }
        return String.join("", words);
    }

    public static String convertToC(String name){
        List<String> words = new LinkedList<>();

        int lastUpper = 0;
        for(int i=0;i<name.length();i++){
            if(name.charAt(i) <= 'Z'){
                words.add(name.substring(lastUpper,i));
                lastUpper = i;
            }
        }
        words.add(name.substring(lastUpper,name.length()));

        return words.stream().map(String::toLowerCase).collect(Collectors.joining("_"));
    }

    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        String input = null;
        while((input = scanner.nextLine()) != null){
            boolean isJava = isJavaName(input);
            boolean isC = isCname(input);
            if(isC && isJava){
                System.out.println(input);
            }
            else if(isC){
                System.out.println(convertToJava(input));
            }
            else if(isJava){
                System.out.println(convertToC(input));
            }
            else{
                System.out.println("Error!");
            }
            input = null;
        }
    }
}

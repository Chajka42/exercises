import java.io.File;
import java.io.IOException;

public class FileOps {


    public static void main(String[] argv) throws IOException {

        File folder = new File("c:/renaming/");
        File[] listOfFiles = folder.listFiles();
          int j = 0, h = 0, k = 0;
        for (int i = 0; i < listOfFiles.length; i++) {

           


            if (listOfFiles[i].isFile()) {

                File f = new File("c:/renaming/"+listOfFiles[i].getName()); 
                String CX = f.toString();
                String zeros, zerosh,zerosk;
                if (j <= 9) {zeros = "00";} else {
                    if (j <= 99) {zeros = "0";} else {zeros = "";}
                }
                if (h <= 9) {zerosh = "00";} else {
                    if (h <= 99) {zerosh = "0";} else {zerosh = "";}
                }
                if (k <= 9) {zerosk = "00";} else {
                    if (k <= 99) {zerosk = "0";} else {zerosk = "";}
                }
                if (Integer.valueOf(CX.substring(13,14)) == 1) {f.renameTo(new File("c:/renaming/C1Trace00" + zeros + j + ".csv"));j++;}
                if (Integer.valueOf(CX.substring(13,14)) == 2) {f.renameTo(new File("c:/renaming/C2Trace00" + zerosh + h + ".csv"));h++;}
                if (Integer.valueOf(CX.substring(13,14)) == 3) {f.renameTo(new File("c:/renaming/C3Trace00" + zerosk + k + ".csv"));k++;}
            }
            
        }

        System.out.println("conversion is done");
    }
}
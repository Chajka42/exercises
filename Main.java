import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
//import java.util.ArrayList;
import java.util.Arrays;
//import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException  {



        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"))) {
            int N = Integer.valueOf(reader.readLine());
            N -= 2;


String [] dataPrimo = new String [N];   
short [][] findata = new short [N][2];     
            for (int y = 0; y < N; y++){


                String [] arr = reader.readLine().split(" ", 2);
                 dataPrimo[y] = String.join(" ", arr[1]).replaceAll(" ", "") ; 
            }


//for (int i = 0; i < N; i++){ 
    for (int j = 0; j < N; j++){
        for (int k = 0; k < dataPrimo[j].length(); k++){
            if (Character.getNumericValue(dataPrimo[j].charAt(k)) > 2) 
            { dataPrimo[j] = dataPrimo[j].substring(0, k) + dataPrimo[(Character.getNumericValue(dataPrimo[j].charAt(k))-3)] + dataPrimo[j].substring(k+1, dataPrimo[j].length());
               
            }
        }
    }
//}

for (int i = 0; i < N; i++){
    char[] chars = dataPrimo[i].toCharArray();
        Arrays.sort(chars);
        if (Character.getNumericValue(chars[chars.length - 1]) < 3) {
        for (int h = 0; h < chars.length; h++) {
            if (chars[h] == '1'){findata[i][0] += 1;} else {findata[i][1] += 1;}
        }
    } else {findata[i][0] = 0; findata[i][1] = 0;}
}


int nTask = Integer.valueOf(reader.readLine());
String finalle = "";
String[] arra = new String [3]; 
for (int y = 0; y < nTask; y++){
    arra = reader.readLine().split(" ");
    if (findata[(Integer.valueOf(arra[2])-3)][0] + findata[(Integer.valueOf(arra[2])-3)][1] != 0 && findata[(Integer.valueOf(arra[2])-3)][0] <= Integer.valueOf(arra[0]) && findata[(Integer.valueOf(arra[2])-3)][1] <= Integer.valueOf(arra[1])) 
    {finalle += "1";} else {finalle += "0";}
}



try (FileWriter writer = new FileWriter("output.txt")) {
    writer.write(finalle);
    writer.flush();
}

        }}

    
}



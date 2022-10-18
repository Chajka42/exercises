public class Febonnachi {

    public static int GOO (int PUTTEN){
        int GOO = 1, GOO1 = 1, GOO2 = 1;
        for (int i = 2; i < PUTTEN;){
            GOO2 = GOO1 + GOO;
            GOO = GOO1;
            GOO1 = GOO2;
            i++;
        }
        return GOO2;
        
    }
}

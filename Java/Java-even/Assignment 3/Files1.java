import java.io.*;

class FileThread implements Runnable{
    File file;
    String word;
    public FileThread(File file, String word){
        this.file = file;
        this.word = word;
    }
    
    public void run(){
        try{
                BufferedReader br = new BufferedReader(new FileReader(file));
                String str;    
                while((str = br.readLine()) != null){
                    
                    if(str.contains(word)){
                        System.out.print("File :" + file.getName() + "\n");
                        break;
                    }
                }
        }
        catch(Exception e){}
    }
}

public class Files1{
    public static void main(String[] args){
        try{
                int i = 0; 
                File dir = new File(args[0]);
		Thread t[] = new Thread[50];
                FileThread[] ft = new FileThread[50];
                for(File fileEntry: dir.listFiles()){
                    if(!fileEntry.isDirectory() && fileEntry.getName().contains(".txt"))
                   {                    
                            ft[i++] = new FileThread(fileEntry, args[1]);
                            t[i-1] = new Thread(ft[i-1]);
                            t[i-1].start();
                    }
                }

        }
        catch(Exception e){}

    }
}

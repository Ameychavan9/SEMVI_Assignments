//Thread to print prime numbers
class Prime extends Thread{
	public void run(){
		int i=0,num=0;
		String primeNumbers="";
		
		for(i=1;i<=100;i++){
			int counter=0;
			for(num=i;num>=1;num--){
				if(i%num==0){
					counter=counter+1;
				}
			}
			if(counter==2){
				primeNumbers=primeNumbers+i+" ";
			}
		}
		System.out.println("\nPrime numbers from 1 to 100:\n"+primeNumbers);

		System.out.println();
		
	}
}

//Thread to print pallindrome

class Pallindrome extends Thread{
	public void run(){
		int n,b,rev=0;
		int N=100;
		System.out.println("Pallindrome numbers from 1 to 100:\n");
		
		for(int i=10;i<=N;i++){
			n=i;
			while(n>0){
				//find reverse of n
				b=n%10;
				rev=rev*10+b;
				n=n/10;
			}
			//If n and rev are same n is pallindrome number
			if(rev==i){
				System.out.println(i+" ");
			}
			rev=0;
		}
	}
}

class As3Q3{
	public static void main(String args[]){
		Prime p1=new Prime();
		Pallindrome p2=new Pallindrome();
		
		Thread m1=new Thread(p1);
		Thread m2=new Thread(p2);

		m1.start();
		m2.start();

		try{
			m1.join();
			m2.join();
		}
		catch(InterruptedException e){
			System.out.println(e);
		}
	}
}

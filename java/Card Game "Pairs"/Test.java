import java.util.Random;
public class Test{
	private static int[] arr = new int[20];
	private static int[] arr2 = new int[2];
	private static boolean[] arr3 = new boolean[20];
	public static boolean duplicate(){
		for(int i = 0; i < arr.length; i++){
			for(int j = i + 1; j < arr.length; j++){
				if(arr[i] == arr[j] && !arr3[i] && !arr3[j] && arr[i] != -1 && arr[j] != -1){
					arr[0] = i;
					arr[1] = j;
					return true;
				}
			}
		}
		return false;
	}

	public static void main(String[] args){
		Random rand = new Random();
		for(int i = 0 ; i < arr3.length;i++){
			arr3[i] = false;
		}
		for(int i = 0; i < arr.length; i++){
			arr[i] = -1;
		}
		for(int i = 0; i < arr.length; i++){
			int rand1 = rand.nextInt(20);
			int rand2 = rand.nextInt(10);
			arr[rand1] = rand2;
		}

		for(int i = 0; i < arr.length;i++){
			if(arr[i] != -1 && arr[i] > 5){
				arr3[i] = true;
			}
		}
		for(int i = 0; i < arr.length; i++){
			System.out.print("|"+arr[i]+"|");
		}
		System.out.print("\n");
		for(int i = 0; i < arr.length; i++){
			System.out.print("|"+arr3[i]+"|");
		}
		if(duplicate()){
			System.out.println(arr[0]);
			System.out.println(arr[1]);
		}else{
			System.out.println("false");
		}



	}
}
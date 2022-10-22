public class SumofNumber{

public static void main(String[] args) {
    
    int[] arr1={1,2,3,4,5};
    int[] arr2={1,3,4,5,6};
    int[] arr3={3,4,5,7};
    int sum=10,count=0;

    for(int i=0;i<arr1.length;i++)
        {
            for(int j=0; j<arr2.length;j++)
            {
                int target=sum-(arr1[i]+arr2[j]);

                
                if(binarySearch(arr3,0,arr3.length-1,target))
                {
                    count++;
                    System.out.println(arr1[i]+" "+arr2[j]+" "+target+" ");
                }
            }
        }

        if(count==0){System.out.println("No such Tripplets exists");}
        else{System.out.println(count+" Tripplets in total exist as shown above");}

}

    static boolean binarySearch(int[] arr,int start, int end, int target)
        {

            while(start<=end)
            {
                int mid=start+(end-start)/2;

                if(arr[mid]<target){start=mid+1;}
                else if(arr[mid]>target){end=mid-1;}
                else{return true;}
            }
            return false;
            
        }

}
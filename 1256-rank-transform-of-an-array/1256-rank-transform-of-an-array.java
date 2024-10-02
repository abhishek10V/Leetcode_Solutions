class Solution {
    public int[] arrayRankTransform(int[] arr) {

        int[] temp = new int[arr.length];
        for(int i=0 ; i<arr.length; i++) temp[i] = arr[i];


        Arrays.sort(temp);
      
        HashMap<Integer , Integer> map = new HashMap<>();

        for(int i=0 ; i<temp.length; i++){
            if(!map.containsKey(temp[i])){
                map.put(temp[i] , map.size() + 1);
            }
        }


        temp = new int[arr.length];
        for(int i=0 ;i<arr.length; i++){
            temp[i] = map.get(arr[i]);
        }
        return temp;
    }
}
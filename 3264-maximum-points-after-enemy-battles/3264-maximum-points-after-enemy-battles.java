class Solution {
    public long maximumPoints(int[] eEnergy, int cEnergy) {
        Arrays.sort(eEnergy);
        long energy = cEnergy;
        if(eEnergy[0] > cEnergy) return 0;
        for(int i=1; i<eEnergy.length; i++) energy += eEnergy[i];

        return energy/eEnergy[0];
        
    }
}
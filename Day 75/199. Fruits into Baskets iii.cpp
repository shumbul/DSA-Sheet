class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int> maxInSector;
        int totalBaskets = baskets.size();
        int sectorLength = sqrt(totalBaskets);
        // Preprocess: build max for each sector
        int count = 0, currentMax = 0;
        for (int i = 0; i < totalBaskets; i++) {
            if (count == sectorLength) {
                maxInSector.push_back(currentMax);
                currentMax = baskets[i];
                count = 1;
            } 
            else {
                count++;
                currentMax = max(currentMax, baskets[i]);
            }
        }
        maxInSector.push_back(currentMax); // Last sector
        int unplaced = 0;
        // Try placing each fruit
        for (int fruit : fruits) {
            int sectorId = 0;
            bool placed = false;
            for (int sectorStart = 0; sectorStart < totalBaskets; sectorStart += sectorLength) {
                if (maxInSector[sectorId] < fruit) {
                    sectorId++;
                    continue; // skip sector
                }
                // Try to place fruit in this sector
                for (int i = sectorStart; i < min(sectorStart + sectorLength, totalBaskets); i++) {
                    if (baskets[i] >= fruit) {
                        placed = true;
                        baskets[i] = 0;
                        break;
                    }
                }
                // If placed, update sector max
                if (placed) {
                    maxInSector[sectorId] = 0;
                    for (int i = sectorStart; i < min(sectorStart + sectorLength, totalBaskets); i++) {
                        maxInSector[sectorId] = max(maxInSector[sectorId], baskets[i]);
                    }
                    break;
                }
                sectorId++;
            }
            if (!placed) unplaced++;
        }
        return unplaced;
    }
};

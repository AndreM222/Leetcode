class ParkingSystem
{
  private:
    // Parking Slots
    vector<int> slot;

  public:
    ParkingSystem(int big, int medium, int small)
    {
        // Setup max cars in every type slot
        slot.push_back(big);
        slot.push_back(medium);
        slot.push_back(small);
    }

    bool addCar(int carType)
    {
        // Detect if valid input
        if (carType > 0 && carType <= 3)
        {
            // Check if slot avaiable in position carType - 1 to have index 0, 1, 2
            if (slot[carType - 1] > 0)
            {
                // If spot available then take slot and return true
                slot[carType - 1]--;
                return true;
            }
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

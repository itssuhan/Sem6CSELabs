class SubsetGenerator:
    def __init__(self, nums):
        self.nums = nums  # store numbers
        self.subsets = []  # store subsets

    def generate_subsets(self):
        self.subsets.clear()

        self._generate([], 0)

        return self.subsets

    def _generate(self, current_subset, start_index):
        # if start_index = Length of Nums -> All Integers have been considered

        if start_index == len(self.nums):
            self.subsets.append(current_subset[:])
            # self.subsets.append(current_subset[:]) ensures that we add a copy of the current subset to the list of
            # subsets, preserving the state of the subset at the time of appending and avoiding unintended
            # modifications later on.
            return

        # Recursive step: Include the current number in the subset, then generate subsets starting from the next index

        current_subset.append(self.nums[start_index])
        self._generate(current_subset, start_index + 1)

        current_subset.pop()
        self._generate(current_subset, start_index + 1)


nums = [1, 2, 3]
subset_generator = SubsetGenerator(nums)
all_subsets = subset_generator.generate_subsets()

print("Generated Subsets")
for subset in all_subsets:
    print(subset)

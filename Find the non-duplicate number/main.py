def singleNumber(nums):
  # Fill this in.
  # set remove duplicate elements. nums = [1, 2, 3, 4, 2, 3, 4]
  # set(nums) = [1, 2, 3, 4] and we have to do this:
  # 2*nums - nums = [1, 1, 2, 2, 3, 3, 4, 4] - [1, 2, 2, 3, 3, 4, 4] = [1]
  return 2*sum(set(nums)) - sum(nums)

print (singleNumber([4, 3, 2, 4, 1, 3, 2]))
# 1
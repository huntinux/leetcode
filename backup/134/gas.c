
/*
 There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

Subscribe to see which companies asked this question

*/

// 这个分析很到位： http://www.cnblogs.com/felixfang/p/3814463.html
/*
diff[i] = gas[i] - cost[i]
所有diff加起来如果>=0,那么一定存在。使用total来表示diff的和。
尝试从diff[0]开始，如果sum += diff[i]之后，sum<0了，那么说明，我们应该
从diff[i+1]重新尝试了。因此sum重新置0，记录索引index=i+1。如果一直到最后一个位置，sum都是大于0的，如果total>=0, 那么index就是答案。

什么？为什么不重新计算从 diff[0] 到 diff[index-1]? 

因为已经加到total里面啦。

*/

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {

	int total = 0, sum = 0, index = 0;

	for(int i = 0; i < gasSize; i++) {
		sum += gas[i] - cost[i];
		total += gas[i] - cost[i];
		if(sum < 0) {
			index = i + 1;
			sum = 0;
		}
	}


	return total >= 0 ? index : -1;

}

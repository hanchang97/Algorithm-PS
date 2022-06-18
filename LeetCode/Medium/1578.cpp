class Solution {
public:
	int minCost(string colors, vector<int>& neededTime) {

		int max = neededTime[0];
		int sum = neededTime[0];
		int answer = 0;

		for (int i = 1; i < colors.length(); i++) {
			if (colors[i] == colors[i - 1]) {
				sum += neededTime[i];
				if (neededTime[i] > max) max = neededTime[i];
			}
			else {
				answer += (sum - max);
				sum = neededTime[i];
				max = neededTime[i];
			}
		}

		answer += (sum - max);  // 연속된 문자로 끝나는 경우를 위함

		return answer;
	}
};

/*

연속된 부분에서 비용이 가장 큰 값을 제외한 나머지를 모두 제거
연속된 부분의 합 구하고 가장 큰 값만 뺀 것을 누적해서 더한다

*/
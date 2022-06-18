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

		answer += (sum - max);  // ���ӵ� ���ڷ� ������ ��츦 ����

		return answer;
	}
};

/*

���ӵ� �κп��� ����� ���� ū ���� ������ �������� ��� ����
���ӵ� �κ��� �� ���ϰ� ���� ū ���� �� ���� �����ؼ� ���Ѵ�

*/
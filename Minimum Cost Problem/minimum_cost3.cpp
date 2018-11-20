int min_cost(int** input, int si, int sj, int ei, int ej) {
	if (si == ei && sj == ej) {
		return input[ei][ej];
	}
	if (si > ei || sj > ej) {
		return INT_MAX;
	}
	int option1 = min_cost(input, si + 1, sj, ei, ej);
	int option2 = min_cost(input, si + 1, sj + 1, ei, ej);
	int option3 = min_cost(input, si, sj + 1, ei, ej);
	return input[si][sj] + min(option1, min(option2, option3));
}

def solution(info, n, m):
    from collections import defaultdict
    MAX = float('inf')
    length = len(info)

    # dp[i][b] = a -> i개의 물건을 고려했고, B의 흔적이 b일 때, A의 최소 흔적이 a
    dp = [defaultdict(lambda: MAX) for _ in range(length + 1)]
    dp[0][0] = 0

    for i in range(length):
        a_trace, b_trace = info[i]
        for b_total in list(dp[i].keys()):  # list()로 복사해서 안전하게 순회
            a_total = dp[i][b_total]

            # Case 1: A가 훔침
            if a_total + a_trace < n:
                dp[i + 1][b_total] = min(dp[i + 1][b_total], a_total + a_trace)

            # Case 2: B가 훔침
            if b_total + b_trace < m:
                dp[i + 1][b_total + b_trace] = min(dp[i + 1][b_total + b_trace], a_total)

    # 가능한 결과 후보들을 모음
    candidates = [dp[length][b] for b in dp[length] if dp[length][b] < n]

    return min(candidates) if candidates else -1

def solution(k, dungeons):
    return explore_dungeons(k,dungeons)

def explore_dungeons(k, dungeons):
    def backtrack(remaining_stamina, visited):
        if all(visited):
            return 0  # 모든 던전을 방문했으면 더 이상 탐험할 수 없음

        max_dungeons = 0
        for i in range(len(dungeons)):
            if not visited[i]:
                required_stamina, used_stamina = dungeons[i]
                if remaining_stamina >= required_stamina:
                    visited[i] = True  # 던전 방문 표시
                    # 재귀적으로 다음 던전 탐색하면서 방문한 던전 수를 증가
                    max_dungeons = max(max_dungeons, 1 + backtrack(remaining_stamina - used_stamina, visited))
                    visited[i] = False  # 던전 방문 해제

        return max_dungeons
    return backtrack(k, [False] * len(dungeons))
class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)
        children = [[] for _ in range(n)]
        for node in range(1, n):
            children[parent[node]].append(node)

        closest_ancestor = [-1] * 26
        new_parent = parent[:]
        subtree_size = [1] * n

        def dfs(u: int) -> None:
            char_idx = ord(s[u]) - ord('a')

            if u != 0 and closest_ancestor[char_idx] != -1:
                new_parent[u] = closest_ancestor[char_idx]

            prev_ancestor = closest_ancestor[char_idx]
            closest_ancestor[char_idx] = u

            for v in children[u]:
                dfs(v)

            closest_ancestor[char_idx] = prev_ancestor

            if u != 0:
                subtree_size[new_parent[u]] += subtree_size[u]

        dfs(0)
        return subtree_size
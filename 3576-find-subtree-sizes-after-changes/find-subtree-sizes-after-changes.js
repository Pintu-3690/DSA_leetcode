/**
 * @param {number[]} parent
 * @param {string} s
 * @return {number[]}
 */
var findSubtreeSizes = function (parent, s) {
  const n = parent.length;
  const origTree = Array.from({ length: n }, () => []);
  for (let i = 1; i < n; i++) {
    origTree[parent[i]].push(i);
  }

  const finalParent = Array(n).fill(-1);
  const lastSeen = Array(26).fill(-1);

  function assignParents(node) {
    const code = s.charCodeAt(node) - 97;
    if (node > 0) {
      finalParent[node] = lastSeen[code] !== -1 ? lastSeen[code] : parent[node];
    }

    const prev = lastSeen[code];
    lastSeen[code] = node;

    for (const child of origTree[node]) {
      assignParents(child);
    }

    lastSeen[code] = prev;
  }

  assignParents(0);

  const finalTree = Array.from({ length: n }, () => []);
  for (let i = 1; i < n; i++) {
    finalTree[finalParent[i]].push(i);
  }

  const answer = Array(n).fill(0);

  function computeSizes(node) {
    let count = 1;
    for (const child of finalTree[node]) {
      count += computeSizes(child);
    }
    answer[node] = count;
    return count;
  }

  computeSizes(0);
  return answer;
};
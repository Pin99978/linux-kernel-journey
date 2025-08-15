from collections import deque

def show_queue_basics():
    q = deque()
    
    print("Queue demo -> enqueue 1,2,3")
    for x in (1,2,3):
        q.append(x)   # enqueue
    print("Current queue:" , list(q))
    front = q.popleft() #dequeue


class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

def build_sample_tree() -> TreeNode:
    n1 = TreeNode(1)
    n2 = TreeNode(2)
    n3 = TreeNode(3)
    n4 = TreeNode(4)
    n5 = TreeNode(5)
    n6 = TreeNode(6)
    n1.left , n1.right = n2 , n3
    n2.left , n2.right = n4 , n5
    n3.right = n6
    return n1

def bfs_level_order(root: TreeNode) -> None:
    if not root:
        print("empty tree")
        return
    
    q =deque([root])
    level = 0
    while q:
        level_size = len(q) 
        print(f"Level {level}:", end = "")
        for _ in range(level_size):
            node = q.popleft()
            print(node.val, end=" ")
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
            print()
            level += 1
if __name__ == "__main__":
    show_queue_basics()
    root = build_sample_tree()
    print("BFS 層序走訪結果：")
    bfs_level_order(root)            
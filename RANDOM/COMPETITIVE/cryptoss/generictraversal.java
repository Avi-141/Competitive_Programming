// Represents a node in the tree.
public class Node {
  public int Data { get; set; }
  public Node LeftChild { get; set; }
  public Node RightChild { get; set; }
};
 
//  An implementation of this interface can be passed 
//  to 'DoTraversal' method and:
//  OnVisitFromTop   will be invoked when a node is visited from the top
//  OnVisitFromLeft  will be invoked when a node is visited from the left
//  OnVisitFromRight will be invoked when a node is visited from the right
public interface ITreeVisit {
  void OnVisitFromTop(Node node);
  void OnVisitFromLeft(Node node);
  void OnVisitFromRight(Node node);
};
 
// Implementation of ITreeVisit for postorder.
public class PostOrderVisit : ITreeVisit
{
  public void OnVisitFromTop(Node node) {}
  public void OnVisitFromLeft(Node node) {}
  public void OnVisitFromRight(Node node) {
    Console.Write(node.Data + " ");
  }
}
 
// Implementation of ITreeVisit for preorder.
public class PreOrderVisit : ITreeVisit
{
  public void OnVisitFromTop(Node node) { 
    Console.Write(node.Data + " ");
  }
  public void OnVisitFromLeft(Node node) {}
  public void OnVisitFromRight(Node node) {}
}
 
// Implementation of ITreeVisit for inorder.
public class InOrderVisit : ITreeVisit
{
  public void OnVisitFromTop(Node node) {}
  public void OnVisitFromLeft(Node node) {
    Console.Write(node.Data + " ");
  }
  public void OnVisitFromRight(Node node) {}
}
 
// Push the given node and all it's left children to the stack.
void PushThisAndAllLeft(Node node, ITreeVisit visit, Stack stack) {
  if (node == null)
    return;
	
  Node current = node;
  while (current != null) {
    visit.OnVisitFromTop(current);
    stack.Push(current);
	current = current.LeftChild;
  }
}
 
// Do generic tree traversal starting from root, where
// each node will be visited from the top, from the left
// and from the right.
// 
// When a node is visited from the top call
//   ITreeVisit::OnVisitFromTop
// When a node is visited from the left call
//   ITreeVisit::OnVisitFromLeft
// When a node is visited from the right call
//   ITreeVisit::OnVisitFromRight
void DoTraversal(Node root, ITreeVisit visit) {
  Stack stack = new Stack();
  
  // Helper method to check stack is empty
  Func IsStackEmpty = () => {
    return stack.Count() == 0;
  };
  
  // Helper method pop top element from stack and 
  // return it, if statck is empty then return null.
  Func Pop = () => {
    try {
	  return stack.Pop();
	}
	catch(InvalidOperationException) {
	  return null;
	}
  };
  
  PushThisAndAllLeft(root, visit, stack);
  
  Node savedNode = null;
  while (!IsStackEmpty()) {
    Node popped = Pop();
	if (popped == null) {
	  break;
	}
 
	if (popped.LeftChild == null && popped.RightChild == null) {
	  visit.OnVisitFromLeft(popped);
	  visit.OnVisitFromRight(popped);
	  savedNode = popped;
	} else if (popped.LeftChild == savedNode) {
	  visit.OnVisitFromLeft(popped);
	  if (popped.RightChild == null) {
	    visit.OnVisitFromRight(popped);
	    savedNode = popped;
	  } else {
	    stack.Push(popped);
		PushThisAndAllLeft(popped.RightChild, visit, stack);
		savedNode = null;
	  }
	} else if (popped.RightChild == savedNode) {
	  visit.OnVisitFromRight(popped);
	  savedNode = popped;
	}
  }
}
 
Node GetSampleTree()
{
  Node root = new Node {
    Data = 1,
	LeftChild = new Node {
	  Data = 2,
	  LeftChild = new Node {
	    Data = 4,
		RightChild = new Node {
		  Data = 9
		}
	  },
	  RightChild = new Node {
	    Data = 5,
		LeftChild = new Node {
		  Data = 10
		},
		RightChild = new Node {
		  Data = 11
		}
	  }
	},
	RightChild = new Node {
	  Data = 3,
	  LeftChild = new Node {
	    Data = 6,
		LeftChild = new Node {
		  Data = 12
		},
		RightChild = new Node {
		  Data = 13
		}
	  },
	  RightChild = new Node {
	    Data = 7,
		LeftChild = new Node {
		  Data = 14
		},
		RightChild = new Node {
		  Data = 15
		}
	  }
	}
  };
  
  return root;
}
 
void Main()
{
	Node root = GetSampleTree();
	
	Console.WriteLine("\nIn Order:");	
	ITreeVisit visit = new InOrderVisit();
	DoTraversal(root, visit);
	
	Console.WriteLine("\nPre Order:");
	visit = new PreOrderVisit();
	DoTraversal(root, visit);
	
    Console.WriteLine("\nPost Order:");	
	visit = new PostOrderVisit();
	DoTraversal(root, visit);
}
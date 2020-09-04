---
title: The Heap
permalink: /docs/the-heap/
---

### A Simple Class

We will use the simple class below for our examples.

<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public class simple
{
  private int num;
  public simple(int a) { num = a; }
  public void set(int a) { num = a;}
  public int get() { return num; }
}

</code></pre>
<ul>
<li>One variable num</li>
<li>One constructor</li>
<li>One set method</li>
<li>One get method</li>
</ul>
    </div>
    <div class="col-md-6">
    </div>
</div>

### The Setup

#### Code Starts
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
main();
</code></pre>
<ul>
<li>Calling a method adds a frame to the stack</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-1" alt="java heap example">

    </div>
</div>

#### Creating a primitive
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
}
</code></pre>
<ul>
<li>Primitive variables are stored in a frame</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-2" alt="java heap example">

    </div>
</div>

#### Creating a object
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
}
</code></pre>
<ul>
<li>Objects are stored in the Heap</li>
<li>A link to the object is stored in the frame</li>
<li><i>A reference</i></li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-3" alt="java heap example">

    </div>
</div>

#### Objects in memory

Objects are stored on the heap. When an object is created two memory locations are set up  
* In the heap the object is created  
* In the current frame the memory address of that object is stored   
* `simple q = new simple(9);`  
* q stores the memory address, in the heap, of an object of type simple that stores the value 9  


#### Creating an object
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
}
</code></pre>
<ul>
<li>Objects are stored in the Heap</li>
<li>A link to the object is stored in the frame</li>
<li><i>A reference</i></li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-4" alt="java heap example">

    </div>
</div>

#### Changing an object
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
  s_obj.set(10);
}
</code></pre>
<ul>
<li>Changes to the object are changes to the heap</li>
<li>The frame is unchanged</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-5" alt="java heap example">

    </div>
</div>

#### Passing objects as parameters
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
  s_obj.set(10);
  test(i_prim, s_obj);
}
public test(int a, simple b)
{
   a = 6;
   b.set(15);
}
</code></pre>
<ul>
<li>Objects can be passed as parameters</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-6" alt="java heap example">

    </div>
</div>

#### Passing object **links** as parameters
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
  s_obj.set(10);
  <b>test(i_prim, s_obj);</b>
}
public test(int a, simple b)
{
   a = 6;
   b.set(15);
}
</code></pre>
<ul>
<li>Objects can be passed as parameters</li>
<li>Remember though that it is the reference we are passing</li>
<li>The link to the heap</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-7" alt="java heap example">

    </div>
</div>

#### Primitives are passed by **value**
so only the local value changes  
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
  s_obj.set(10);
  test(i_prim, s_obj);
}
public test(int a, simple b)
{
   <b>a = 6;</b>
   b.set(15);
}
</code></pre>
<ul>
<li>Changing the primitive parameter changes only the local variable</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-8" alt="java heap example">

    </div>
</div>

#### Objects are passed by **reference**
so only the local value changes  
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
  s_obj.set(10);
  test(i_prim, s_obj);
}
public test(int a, simple b)
{
   a = 6;
   <b>b.set(15);</b>
}
</code></pre>
<ul>
<li>The object changes on the heap so the object changes everywhere</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-9" alt="java heap example">

    </div>
</div>

#### Objects changes are persistent
They stay changed after the method exits.    
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
  s_obj.set(10);
  test(i_prim, s_obj);
}
public test(int a, simple b)
{
   a = 6;
   b.set(15);
}
</code></pre>
<ul>
<li></li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-10" alt="java heap example">

    </div>
</div>

#### Objects as parameters
Objects themselves are not actually passed as parameters. Instead the memory address of the object is passed. The memory address is passed like a primitive variable.  


#### Object reference is a local primitive variable
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
  s_obj.set(10);
  test(i_prim, s_obj);
}
public test(int a, simple b)
{
   a = 6;
   <b>b.set(15)</b>
   b = new simple(8);
}
</code></pre>
<ul>
<li></li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-10" alt="java heap example">

    </div>
</div>

#### Object reference is a local primitive variable
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
  s_obj.set(10);
  test(i_prim, s_obj);
}
public test(int a, simple b)
{
   a = 6;
   b.set(15)
   <b>b = new simple(8);</b>
}
</code></pre>
<ul>
<li>This creates a new object on the heap</li>
<li>It does not change the original object, nor does it affect the original link</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-11" alt="java heap example">

    </div>
</div>


#### Object scope
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
  s_obj.set(10);
  test(i_prim, s_obj);
}
public test(int a, simple b)
{
   a = 6;
   b.set(15)
   b = new simple(8);
}
</code></pre>
<ul>
<li>When test() exits, the second object is deleted</li>
<li>Objects are deleted when they have no handles to them</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-10" alt="java heap example">

    </div>
</div>


#### Garbage collection
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
  s_obj.set(10);
  test(i_prim, s_obj);
}
public test(int a, simple b)
{
   a = 6;
   b.set(15)
   b = new simple(8);
}
</code></pre>
<ul>
<li>Technically the object still exists but we have no way to access it</li>
<li>Java’s garbage collection will eventually notice we have no link and delete the object</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-12" alt="java heap example">

    </div>
</div>


#### Garbage collection
#### Some Time Later
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  int i_prim = 3;
  simple s_obj = new simple(5);
  s_obj.set(10);
  test(i_prim, s_obj);
}
public test(int a, simple b)
{
   a = 6;
   b.set(15)
   b = new simple(8);
}
</code></pre>
<ul>
<li>Technically the object still exists but we have no way to access it</li>
<li>Java’s garbage collection will eventually notice we have no link and delete the object</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-13" alt="java heap example">

    </div>
</div>


#### Why are objects and primitives different
Primitive variables are small and of known size  
* They can be passed very quickly by variable  
* Removed automatically with the frame  
Objects vary in size  
* They are big and would be slow to pass around as parameters  
* Their addresses can be passed quickly like primitive variables.  
* Hang around in memory until garbage collection gets round to them  


#### Stack vs Heap
#### Primitives vs Objects
<div class="row">
    <div class="col-md-6">
<b>Stack</b>
<ul>
<li>Allocated as methods are called</li>
<li>Deallocated when method exits</li>
<li>Faster</li>
<li>Limited in size</li>
<li>Threadsafe – threads have their own stacks</li>
</ul>
    </div>
    <div class="col-md-6">
    <b>Heap</b>
<ul>
<li>Allocated when objects are created</li>
<li>Deallocated when garbage collector realises there is no link to object</li>
<li>Slower</li>
<li>Not limited in size</li>
<li>Not threadsafe – the heap is shared</li>
</ul>
    </div>
</div>


#### Instance vs Local Variables
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public class simple
{
  private int num;

  public bigger(int a) 
  { 
    int b = 3;
    num = a + b; 
  }
}
</code></pre>
    </div>
    <div class="col-md-6">
<ul>
<li><b>num</b> is an <i>instance variable</i></li>
<ul>
<li>It is created when the object is created </li>
<li>It is stored in the heap</li>
</ul>
<li><b>b</b> is a <i>local variable</i></li>
<ul>
<li>It is created when the method is called</li>
<li>It is stored in the method frame</li>
</ul>
<li><b>a</b> is also a <i>local variable</i></li>
<li>Remember the code itself is stored elsewhere in memory</li>
</ul>

    </div>
</div>


#### Objects as "="
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  simple s_1 = new simple(5);
  simple s_2 = new simple(7);
}
</code></pre>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-14" alt="java heap example">

    </div>
</div>


#### Objects as "="
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  simple s_1 = new simple(5);
  simple s_2 = new simple(7);

  s_2 = s_1;
}
</code></pre>
<ul>
<li>Assigning one object to another <i>copies the link <b>not</b> the object</i></li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-15" alt="java heap example">

    </div>
</div>

#### Cloning an object
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  simple s_1 = new simple(5);

  simple s_2 = (simple) s_1.clone();
  
}
</code></pre>
<ul>
<li>Most Java classes come with a method called <b>clone()</b></li>
<li>This method returns a new object with the same values as the object is is called on</li>
<li>You would need to create your own clone method for your own classes</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-16" alt="java heap example">

    </div>
</div>

#### Objects - Testing Equality
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  simple s_1 = new simple(5);
  simple s_2 = new simple(5);

  if (s_1 == s_2)
  …
}
</code></pre>
<ul>
<li>This will fail, it will compare the two memory addresses and they will be different</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-17" alt="java heap example">

    </div>
</div>


#### Objects - Testing Equality
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  simple s_1 = new simple(5);
  simple s_2 = new simple(5);

  if (s_1.equals(s_2))
  …
}
</code></pre>
<ul>
<li>This will succeed</li>
<li>Most Java classes implement equals()</li>
<li>You will need to implement equals for your own classes</li>
<li>[Instructions on doing this](https://www.sitepoint.com/implement-javas-equals-method-correctly/)</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-17" alt="java heap example">

    </div>
</div>

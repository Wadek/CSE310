<h1>Project 2</h1>
<h3>Memory allocation and management.</h3>
<ol>The purpose of this assignment is 3-fold:
    <ol> 
        <li>Implementation of hash tables for the symbol table, and to learn implementation of (max) heaps for maintaining free space.</li>
        <li>To allocate, initialize, and perform operations on data structures via memory management functions; includes integers, strings, and binary search trees. </li>
        <li>To become procient in understanding and using pointers, and with the notion of coercion.</li>
    </ol>
</ol>

<h4>Initial Project Notes</h4>
<dl>
    <dt>start with allocating one large free block (using malloc/new)</dt>
    <dt>two main functions</dt>
        <dd>myMalloc() is used to allocate data structures from the block </dd>
        <dd>myFree() is used to return the memory for re-use</dd>
    <dt>(max) heap must be used to implement free space ordered by block size</dt>
    <dt> hash table must be used to implement symbol table using var name as key</dt>
</dl>



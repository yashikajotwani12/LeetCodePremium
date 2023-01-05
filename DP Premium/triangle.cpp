Interview Tip: In-place Algorithms

In-place algorithms overwrite the input to save space, but sometimes this can cause problems. Here are a couple of situations where an in-place algorithm might not be suitable.

The algorithm needs to run in a multi-threaded environment, without exclusive access to the array. Other threads might need to read the array too, and might not expect it to be modified.
Even if there is only a single thread, or the algorithm has exclusive access to the array while running, the array might need to be reused later or by another thread once the lock has been released.
In an interview, you should always check whether or not the interviewer minds you overwriting the input. Be ready to explain the pros and cons of doing so if asked!



Interview Tip: Practice Overriding Your Brains "Assume" Mode!

We humans have a habit of making a lot of assumptions - neurobiologists reassure us that this is quite normal! If we didn't make lots of assumptions, our brains would slow to a crawl like a poorly maintained computer, thanks to the overload of additional information they'd have to process.

In an interview situation, where most of us are at least a little nervous, we are even less likely to question our assumptions. The moment most of us realize that we can solve the problem using the top-to-bottom approach, we will be frantically coding it up to show our interviewer that we can solve the problem.

But this isn't ideal! In an interview, and when solving difficult problems in general, you need to learn to identify the assumptions you're making, and question them in your mind. In some problems, this can be things like assuming that input is sorted, that there will be no invalid cases, that they won't mind you overwriting the input, or even that the environment is single-threaded. In this case, the assumption is assuming that the only way of solving this problem is to work from top to bottom.

The only way to get good at challenging your assumptions is lots of practice. Working in a group with other people preparing for code interviews can help too - learning how other people see problems will widen your own way of seeing problems.
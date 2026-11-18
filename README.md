# Operating Systems Lab Programs

Clean, comment-free C implementations based on the experiments listed in the uploaded Operating System Lab Manual.

## Programs
1. Fork system call
2. Even/odd sum using fork
3. Wait system call
4. Orphan process
5. Zombie process
6. Pipe IPC
7–8. FIFO writer and reader
9–10. Message queue writer and reader
11–12. Shared memory writer and reader
13. FCFS scheduling
14. SJF scheduling
15. Priority scheduling
16. FIFO page replacement
17. LRU page replacement
18. `fork()` with `execl()`
19. `ls | wc` using a pipe

## Compile and run
Open a terminal in the `programs` directory. Compile one program at a time:

```bash
gcc 01_fork.c -o fork
./fork
```

For any other file, replace the source and executable names accordingly.

FIFO, message queue, and shared-memory examples use two separate programs. Run the reader in one terminal and the writer in another. For FIFO, run the reader first so it is waiting for the writer.

These are Linux/POSIX programs. They are intended for a Linux environment or WSL on Windows. The scheduling and page-replacement programs are standalone C programs.

## Important source note
The supplied PDF contains OCR/printing errors and some legacy code that uses removed or unsafe functions such as `gets()`, `conio.h`, and `void main()`. The files here are clean, portable revisions of the listed experiments rather than byte-for-byte copies. Verify them against your instructor's required versions before submission.

  What is a File Stream?                                                                                                              
                                                                                                                                      
  A file stream is an abstraction that wraps everything we've discussed:                                                              
                                                                                                                                      
  FILE *file = fopen("data.txt", "r");

  This FILE object contains:
  ┌─────────────────────────────────┐
  │ FILE Stream Object              │
  ├─────────────────────────────────┤
  │ • File descriptor (OS handle)   │ ← Connection to actual file
  │ • Input/Output Buffer           │ ← The buffering mechanism
  │ • File Position Pointer         │ ← Where we are in the file
  │ • EOF Flag                      │ ← End of file indicator
  │ • Error Flags                   │ ← Error status
  └─────────────────────────────────┘

  The Complete Flow

  Your Program
      ↓
  fgetc(file) ← Uses the FILE stream
      ↓
  Check FILE's buffer (input buffer inside FILE)
      ↓
  If empty, refill from file position pointer
      ↓
  Return character

  Practical Example

  FILE *file = fopen("data.txt", "r");
  // file now contains:
  // - Buffer: empty (or refilled on first read)
  // - File position: 0 (start of file)
  // - EOF flag: not set

  fgetc(file);  // Uses file->buffer, file->position, etc.

  fseek(file, 100, SEEK_SET);
  // Changes: file->position = 100, file->buffer = cleared

  fgetc(file);  // Refills buffer from position 100

  Multiple Streams Can Have Different Buffers

  FILE *file1 = fopen("file1.txt", "r");  // Has its own buffer
  FILE *file2 = fopen("file2.txt", "r");  // Has its own separate buffer

  fgetc(file1);  // Uses file1's buffer
  fgetc(file2);  // Uses file2's buffer (independent)

  STDIN is Also a Stream

  // stdin is a FILE stream created by the system
  fgetc(stdin);     // Same concept, uses stdin's buffer
  scanf("%d", &x);  // Uses stdin's buffer

  So streams are the container that holds:
  - The buffer
  - The file position
  - All the metadata needed to read/write 

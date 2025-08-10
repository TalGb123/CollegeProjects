import hashlib
import math
import textwrap

CHUNK_SIZE = 1024  # bytes

def fake_blake3_hash(data):
      """Simulate BLAKE3-like chunked tree hashing with print output"""
      print(f"Original message ({len(data)} bytes): {data!r}\n")
      
      # Step 1: Split into chunks
      chunks = [data[i:i+CHUNK_SIZE] for i in range(0, len(data), CHUNK_SIZE)]
      print(f"Split into {len(chunks)} chunk(s):")
      for i, chunk in enumerate(chunks):
            print(f"  Chunk {i}: {chunk!r}")
      
      # Step 2: Hash each chunk
      hashed_chunks = []
      print("\nHashing chunks:")
      for i, chunk in enumerate(chunks):
            h = hashlib.sha256(chunk).hexdigest()
            hashed_chunks.append(h)
            print(f"  Hashed Chunk {i}: sha256({chunk!r}) = {h}")
    
    # Step 3: Combine chunks in tree-like fashion
      round_num = 1
      while len(hashed_chunks) > 1:
            print(f"\nCombining chunks - Round {round_num}:")
            new_level = []
            for i in range(0, len(hashed_chunks), 2):
                  left = hashed_chunks[i]
                  right = hashed_chunks[i+1] if i+1 < len(hashed_chunks) else ''
                  combined = left + right
                  combined_hash = hashlib.sha256(combined.encode()).hexdigest()
                  print(f"  Combine [{i}] + [{i+1}]: sha256({left[:8]} + {right[:8]}) = {combined_hash}")
                  new_level.append(combined_hash)
            hashed_chunks = new_level
            round_num += 1

      print("\nFinal root hash:", hashed_chunks[0])
      return hashed_chunks[0]


# Example usage
data = b"This is a long message that we want to hash using a BLAKE3-style Merkle tree structure for educational purposes. " * 10
fake_blake3_hash(data)

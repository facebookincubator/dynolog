# HeartBeat's Ring Buffer

Heartbeat's streaming architecture is built around a highly performant Ringbuffer
that can be single or in Per-CPU arrays and in process or shared memory.


## Usage

Create a ringbuffer (or per-CPU ringbuffer) by either:
  - Passing header + data pointers.
  - Passing a size, then ringbuffer will allocate header and data using default
    allocator.
  - Using the helpers in hbt/ringbuffer/Shm.h to allocate header and data
    in shared memory.

The resulting ringbuffer can be used to create multiple Producers and Consumers.

Producers can only write data while Consumers can only read data. API for both
is transactional. A succesful transaction will produce/consume data, while an
unsuccesful will have no effect. Only one producer can have an active write
transaction at any given time. Similarly, only one consumer can have an active
read transaction at any given time.

Per-CPU ringbuffers are arrays of single ringbuffers, one per online CPU
Individual ringbuffers in the array can be produced/consumed from any CPU,
but contention of concurrent producers (or consumers) is minimized when
they only write/read to the ringbuffer corresponding to the CPU where they
are running. That way, at any given time, only one producer (or consumer) is
accesing one ringbuffer.


## Design Guidelines

 The following use use cases shaped the design:

  1. Split control (buffer's header) and data sections. Shared memory
     segments can be loaded with distinct protection policies and/or
     page sizes.
     E.g. a consumer does not be given write privileges in data section,
     although it does in buffer's header.

  2. Data must be a power of 2. This allow to use bit-shift instead of
     modular arithmethic.
     This constraint favours split control and data sections because
     operative system pages are powers of 2, and control structures
     are small. If both control and data sections where placed in the
     same memory page, data section could use up to half of the
     memory page and the rest would be available for control section,
     but control section is usually a few hundreds of bytes long, wasting
     space. Split control allows data sections to be mapped to their own
     memory pages and fully utilizing them.

  3. Support for address independent shared-memory loading implies that
     pointers cannot be used in regions that could be loaded by multiple
     processes. In the current design, each RingBuffer is local to the
     process and takes the pointers of Header and Data sections mmaped into
     that process' memory space.

  4. Per-CPU arrays of Ringbuffers provide concurrent access with very
     low contention. The only corner case is when a thread is pre-empted
     while producing/consuming the buffer and the newly switched thread
     also tries to produce/consume the buffer. In this case the only
     sane option is to pre-empt the new thread since the thread holding
     the lock is waiting in the same CPU queue.

     There is a risk for dead-lock if the scheduling of the thread holding
     the lock depends on another making progress, for this reason, the user
     must avoid acquiring any locks while in a Ring buffer transaction.

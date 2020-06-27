export declare class BinaryQueue<T extends {}> {
  /**
   * The number of elements in the queue. Only complex objects are accepted, not primitive types
   */
  readonly length: number;
  /**
   * Adds a new element to the queue
   * @param value the element to be added
   */
  push(value: T): number;
  /**
   * Removes the oldest element from the queue
   */
  shift(): T;
}

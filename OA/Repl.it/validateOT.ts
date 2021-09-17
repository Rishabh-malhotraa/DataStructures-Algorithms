interface OperationType {
  op: string;
  count: number;
  chars: string;
}

function isValid(stale: string, latest: string, otjson: string): boolean {
  const ot = new OperationTransformation();

  const operations: OperationType[] = JSON.parse(otjson);

  for (const { op, chars, count } of operations) {
    if (op === 'skip') {
      if (ot.getCursorPosition() + count >= stale.length) return false; // if we skip past end
      ot.skip(stale, count);
    } else if (op === 'insert') {
      stale = ot.insert(stale, chars);
    } else if (op === 'delete') {
      if (ot.getCursorPosition() + count >= stale.length) return false; // if we delete past end
      stale = ot.delete(stale, count);
    }
  }

  return stale === latest;
}

class OperationTransformation {
  private cursorPosition = 0;

  OperationTransformation(initialPosition = 0) {
    this.cursorPosition = initialPosition;
  }

  // update the cursor position
  public skip(text: string, count: number) {
    // truncates count + cusorPosition if it goes beyond text.size()
    this.cursorPosition = Math.min(count + this.cursorPosition, text.length);
  }

  // insert the given string at cursorPosition
  public insert(text: string, insertText: string) {
    text =
      text.substr(0, this.cursorPosition) +
      insertText +
      text.substr(this.cursorPosition);

    this.skip(text, insertText.length);

    return text;
  }

  // delete given number of characters from cursorPosition
  public delete(text: string, count: number) {
    return (
      text.substr(0, this.cursorPosition) +
      text.substr(this.cursorPosition + count) // substr return "" if start position > length of string
    );
  }

  public getCursorPosition() {
    return this.cursorPosition;
  }
}

/*
===================================================================
                        TEST CASES
===================================================================
*/

console.log(
  isValid(
    'Repl.it uses operational transformations to keep everyone in a multiplayer repl in sync.',
    'Repl.it uses operational transformations.',
    '[{"op": "skip", "count": 40}, {"op": "delete", "count": 47}]'
  )
); // true

console.log(
  isValid(
    'Repl.it uses operational transformations to keep everyone in a multiplayer repl in sync.',
    'Repl.it uses operational transformations.',
    '[{"op": "skip", "count": 45}, {"op": "delete", "count": 47}]'
  )
); // false, delete past end

console.log(
  isValid(
    'Repl.it uses operational transformations to keep everyone in a multiplayer repl in sync.',
    'Repl.it uses operational transformations.',
    '[{"op": "skip", "count": 40}, {"op": "delete", "count": 47}, {"op": "skip", "count": 2}]'
  )
); // false, skip past end

console.log(
  isValid(
    'Repl.it uses operational transformations to keep everyone in a multiplayer repl in sync.',
    'We use operational transformations to keep everyone in a multiplayer repl in sync.',
    '[{"op": "delete", "count": 7}, {"op": "insert", "chars": "We"}, {"op": "skip", "count": 4}, {"op": "delete", "count": 1}]'
  )
); // true

console.log(
  isValid(
    'Repl.it uses operational transformations to keep everyone in a multiplayer repl in sync.',
    'Repl.it uses operational transformations to keep everyone in a multiplayer repl in sync.',
    '[]'
  )
); // true

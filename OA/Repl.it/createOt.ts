import * as assert from 'assert';

type Keystroke = {
  append: string
} | {
  backspace: true,
} | {
  right: true,
}

type OTOp = {
  op: 'insert',
  chars: string,
} | {
  op: 'delete',
  count: number,
} | {
  op: 'skip',
  count: number,
}

/**
 * Converts a set of keystrokes into their corresponding OT ops.
 * 
 * @param {string} document
 * @param {Keystroke[]} keystrokes
 * 
 * @returns OTOp[]
 */

const createInsert = (s: string): OTOp => {
  return {
    op: 'insert',
    chars: s,
  }
}

const createSkip = (count: number): OTOp => {
  return {
    op: 'skip',
    count: count,
  }
}

const createDelete = (count: number): OTOp => {
  return {
    op: 'delete',
    count: count,
  }
}


// skip - backspace - append   -->  delete  || insert 
// skip - append - backspace   -->  skip    || insert  
// backspace - skip - append   -->  skip    || insert
// backspace - append - skip   -->  insert  || skip
// append - skip - backspace   -->  insert  || delete
// append - backspace - skip   -->  insert  || skip

function keystrokesToOTs(document: string, keystrokes: Array<Keystroke>): Array<OTOp> {
  // you write this!
  let word: string = "";
  let cursor: number = 0;
  let count: number = 0;
  let deleteWord: number = 0;
  let otjson = [] as OTOp[];


  const pushSkipDeleteObject = () => {
    if (count != 0 ) {
      if(deleteWord == 0){ 
        otjson.push(createSkip(count));
      } else { 
        otjson.push(createDelete(deleteWord))
      }
      deleteWord = count = 0;
    }
  }

  const pushInsertObject = () => {
    if (word.length > 0) {
      otjson.push(createInsert(word));
      word = "";
    }
  }

  for (let keystroke of keystrokes) {

    if ("append" in keystroke) {
      pushSkipDeleteObject();
      word = word + keystroke.append;
    }

    else if ("backspace" in keystroke) {
      if (word.length + document.length > 0) {
        word = word.substr(0, word.length - 1) // abc => ab 
        deleteWord = deleteWord + 1;
      }
    }

    else if ("right" in keystroke) {
      pushInsertObject();
      if (cursor + 1 <= document.length + word.length) {
        cursor = cursor + 1;
        count = count + 1;
      }
    }
  }

  pushInsertObject();
  pushSkipDeleteObject();

  return otjson;
}

/**
 * Helper function to test that your code matches the expected solution.
 * 
 * Throws an error if a test case fails.
 * Check the message and stack trace for more detail.
 */
function checkKeystrokesToOTs(document: string, keystrokes: Array<Keystroke>, expectedOTs: Array<OTOp>) {
  const converted = JSON.stringify(keystrokesToOTs(document, keystrokes));
  const expected = JSON.stringify(expectedOTs);

  const match = expected === converted;
  console.log(`${match ? 'pass' : 'fail'} keystrokesToOTs("${document}", ${JSON.stringify(keystrokes)}) -> ${converted})`);
  assert.strictEqual(converted, expected);
}

// 1. Append only
checkKeystrokesToOTs('', [], []);
checkKeystrokesToOTs('', [{ 'append': 'a' }], [{ 'op': 'insert', 'chars': 'a' }]);
checkKeystrokesToOTs('', [{ 'append': 'a' }, { 'append': 'b' }, { 'append': 'c' }], [{ 'op': 'insert', 'chars': 'abc' }]);

// 2. Append + Backspace
checkKeystrokesToOTs('', [{ 'backspace': true }], []);
checkKeystrokesToOTs('', [{ 'append': 'a' }, { 'backspace': true }], []);
checkKeystrokesToOTs('', [{ 'append': 'a' }, { 'append': 'b' }, { 'backspace': true }, { 'append': 'c' }], [{ 'op': 'insert', 'chars': 'ac' }]);
checkKeystrokesToOTs('', [{ 'append': 'a' }, { 'backspace': true }, { 'backspace': true }], []);
checkKeystrokesToOTs('', [{ 'backspace': true }, { 'backspace': true }, { 'append': 'a' }, { 'append': 'b' }], [{ 'op': 'insert', 'chars': 'ab' }]);

// 3. Append + Backspace + Right
checkKeystrokesToOTs('a', [{ 'right': true }, { 'append': 'b' }], [{ 'op': 'skip', 'count': 1 }, { 'op': 'insert', 'chars': 'b' }]);
checkKeystrokesToOTs('a', [{ 'right': true }, { 'backspace': true }], [{ 'op': 'delete', 'count': 1 }]);
checkKeystrokesToOTs('a', [{ 'right': true }, { 'right': true }, { 'append': 'b' }], [{ 'op': 'skip', 'count': 1 }, { 'op': 'insert', 'chars': 'b' }]);
checkKeystrokesToOTs('ac', [{ 'right': true }, { 'append': 'b' }, { 'right': true }, { 'append': 'd' }], [{ 'op': 'skip', 'count': 1 }, { 'op': 'insert', 'chars': 'b' }, { 'op': 'skip', 'count': 1 }, { 'op': 'insert', 'chars': 'd' }]);

const TinyQueue = require("tiny-queue");
const bin = require("./index");
const { expect } = require("chai");

it("Is faster than javascript implementation", () => {
  const jsQueue = new TinyQueue();
  const binQueue = new bin.BinaryQueue();

  let jsTime = process.hrtime();
  for (let i = 0; i < 1000000; i++) {
    jsQueue.push({ i });
  }
  jsTime = process.hrtime(jsTime);
  jsTime = jsTime[0] + jsTime[1] / 1e9;
  let binTime = process.hrtime();
  for (let i = 0; i < 1000000; i++) {
    binQueue.push({ i });
  }
  binTime = process.hrtime(binTime);
  binTime = binTime[0] + binTime[1] / 1e9;

  console.log(`Push time for js: ${jsTime}`);
  console.log(`Push time for bin: ${binTime}`);

  jsTime = process.hrtime();
  while (jsQueue.length > 0) {
    jsQueue.shift();
  }
  jsTime = process.hrtime(jsTime);
  jsTime = jsTime[0] + jsTime[1] / 1e9;

  binTime = process.hrtime();
  while (binQueue.length > 0) {
    binQueue.shift();
  }
  binTime = process.hrtime(binTime);
  binTime = binTime[0] + binTime[1] / 1e9;

  console.log(`Shift time for js: ${jsTime}`);
  console.log(`Shift time for bin: ${binTime}`);
});

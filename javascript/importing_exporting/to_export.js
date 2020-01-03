
// ONE WAY
function gather(name,age) {
  return (name,age);
}

export {gather};

// HERE IS ANOTHER WAY

export function hey(msg) {
  alert(msg);
}

// HERE IS ANOTHER WAY

export default function say_bye(bye_msg) {
  alert(bye_msg);
}

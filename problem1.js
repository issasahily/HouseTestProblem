const validateEmail = (email) => {
  if (email.trim().length < 256) {
    if (email.search("@")) {
      if (email.findall((e) => e == "@").length > 2) {
        return false;
      } else if (email.search("@") == 0 || email.search("@") == email.length) {
        return false;
      } else {
        return true;
      }
    }
  } else return false;
};

validateEmail("");

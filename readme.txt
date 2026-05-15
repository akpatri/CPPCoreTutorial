/*
- Start with compact full summary at top in /**/ so reader understand full thing at a glance
inside /**/
GOOD:
1.int socket(int domain, int type, int protocol) //explanation of this this function
    parameter:
        domain: <description and available option>
        type: <description and available option>
        protocol: <description and available option>
    returns:
        - socket fd on success
        - -1 on failure

2.
compress unnecessary newline
bad: socket() explaing again
if you are explaing function use tree like hierarchy for better undertanding,,
dont consume much space for seperating function,, use something like javadoc
  

- One function = one concept only
- complext command should have explanation side to it like //explanation
- Use simple separator comments before functions
- Add small inline comments beside important code
- Prefer teaching through comments near code
- Add complete main() at end

*/
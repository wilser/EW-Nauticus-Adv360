# Claude & VSCode Notes

## Auto Memory — cross-computer sync via Dropbox

Claude Code stores per-project memory locally by default (not synced). The `autoMemoryDirectory` setting redirects **only the memory folder** to a custom path — it does not move other Claude session data or project files.

Add to **user settings** (`~/.claude/settings.json`) on each computer. This is fixed and cannot change for security.

```json
{
  "autoMemoryDirectory": "C:/Users/yourname/Dropbox/_claude_memory"
}
```

- Use an absolute path with forward slashes (works on Windows). Tilde (`~`) expansion also works but an explicit path is safer across machines if the home dir differs.
- Must be in **user settings**, not project settings (security restriction).
- Set the same Dropbox path on each computer; Dropbox handles the sync.
- The _actual_ path will differ between computers.


### Memory folder structure

```
_claude_memory/
  MEMORY.md              ← root index, always loaded at conversation start
  wilser-K360/
    memory/
      MEMORY.md          ← project-specific memory
      feedback_*.md      ← individual memory files
  other-future-project/
    memory/
      MEMORY.md
```

> [!warning]+ NOTE
> We only moved the `memory` files/folder. The other UUID folders and files are more transient session stuff and are local to each device.


### Project resolution (no slug derivation)

The root `MEMORY.md` contains an explicit table mapping project names to folders. Claude matches the current working directory against the "contains" column:

| Project | Working directory contains | Memory folder |
|---------|---------------------------|---------------|
| wilser-K360 | `wilser-K360` | `wilser-K360/memory/MEMORY.md` |

This approach is cross-computer safe — no path-derived slugs that would differ between machines. Adding a new project = one new table row + one new folder.

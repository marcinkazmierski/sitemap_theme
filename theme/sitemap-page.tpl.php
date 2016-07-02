<div class="container">
    <h1 class="page-title">
        <?php print t('Sitemap'); ?>
    </h1>

    <div class="sitemap">
        <ul class="sitemap-list">
            <?php foreach ($items as $item): ?>
                <li class="sitemap-item">
                    <h2 class="sitemap-section-title">
                        <a href="<?php print $item['url']; ?>" class="sitemap-link">
                            <?php print $item['title']; ?>
                        </a>
                    </h2>
                    <?php if (!empty($item['children'])): ?>
                        <ul class="sitemap-section-list">
                            <?php foreach ($item['children'] as $child): ?>
                                <li class="sitemap-section-item">
                                    <a href="<?php print $child['url']; ?>" class="sitemap-link">
                                        <?php print $child['title']; ?>
                                    </a>
                                </li>
                            <?php endforeach; ?>
                        </ul>
                    <?php endif; ?>
                </li>
            <?php endforeach; ?>
        </ul>
    </div>
</div>
